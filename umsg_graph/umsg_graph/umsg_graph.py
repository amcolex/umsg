from pathlib import Path
import argparse
import glob
import re
import graphviz

def create_graph(source_directories, colors, output_directory):

    # extract directories list
    directories_list = source_directories.split(';')

    # extract colors if any
    if colors is not None:
        colors_list = colors.split(';')

        # check that directories and colors are the same length
        if len(directories_list) != len(colors_list):
            print('Error: number of directories and colors must be the same')
            return

    # create dictionary for all nodes. each node is a source file, color, and its umsg api calls
    nodes_dict = {}
    # Go through each directory
    for index, directory in enumerate(directories_list):
        directory_path = Path().resolve() / directory
        print(directory_path)

        # find all *.c source files recursively
        files = glob.glob(str(directory_path) + '/**/*.c', recursive=True)

        for file in files:
            f = open(file)
            print(file)

            # find strings following the template umsg_topic_message_api(parameters)
            api_calls = re.findall(r'umsg_\w+\([^()]*\)', f.read())
            f.close()

            # node name is the file name
            node_name = Path(file).stem

            # add node to dictionary
            nodes_dict[node_name] = {'api_calls' : [], 'color' : colors_list[index]}

            # extract all umsg api calls from the file
            for function in api_calls:
                # exctract function name
                function_name = function.split('(')[0]
                # extract function parameters
                function_parameters = function.split('(')[1].split(')')[0].split(',')

                # split function name into umsg_topic_message_api tokens
                function_tokens = function_name.split('_')

                # create dictionary for the api call
                api_call_dict = {}
                api_call_dict['topic'] = function_tokens[1]
                api_call_dict['message'] = function_tokens[2]
                api_call_dict['api'] = function_tokens[3]
                api_call_dict['parameters'] = function_parameters

                # add key words to files_dict	
                nodes_dict[node_name]['api_calls'].append(api_call_dict)

    # create graph
    graph = graphviz.Digraph(comment='uMsg Graph')

    # list of nodes which contain links to other nodes
    active_nodes_names = []	

    # create edges between nodes wich share a message, from 'publish' to 'receive' or 'peek'
    for node in nodes_dict:
        for node2 in nodes_dict:
            if node != node2:
                for api_call in nodes_dict[node]['api_calls']:
                    for api_call2 in nodes_dict[node2]['api_calls']:
                        if api_call['message'] == api_call2['message']:
                            if api_call['api'] == 'publish' and (api_call2['api'] == 'receive' or api_call2['api'] == 'peek'):
                                # create edge label as topic.message
                                edge_label = api_call['topic'] + '.' + api_call['message']
                                
                                # add edge to graph
                                # if peek api, or receive with timeout parameter set to 0, then edge is dashed (async)
                                if api_call2['api'] == 'peek' or (api_call2['api'] == 'receive' and api_call2['parameters'][2] == '0'):
                                    graph.edge(node, node2, style='dashed', label=edge_label)
                                else:
                                    graph.edge(node, node2, label=edge_label)

                                # add to active nodes if not already there
                                if node not in active_nodes_names:
                                    active_nodes_names.append(node)
                                if node2 not in active_nodes_names:
                                    active_nodes_names.append(node2)

    # for each node, setting display attributes: box and assigned color
    for node_name in active_nodes_names:
        graph.node(node_name,shape='box')
        graph.node(node_name,style='filled', fillcolor=nodes_dict[node_name]['color'])

    # output graph settings
    graph.body.append('rankdir=LR')

    # generate graph file as svg
    output_path = Path().resolve() / output_directory
    graph.render(output_path / 'umsg_graph', view=True, format='svg')


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', dest='source_directories', required=True)
    parser.add_argument('-c', dest='colors', required=False)
    parser.add_argument('-o', dest='output_directory', required=True)

    args = parser.parse_args()
    create_graph(args.source_directories, args.colors, args.output_directory)