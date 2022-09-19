from pathlib import Path
import argparse
import glob
import re
import graphviz
import json

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
                # extract function parameters without spaces
                function_parameters = function.split('(')[1].split(')')[0].replace(' ', '').split(',')
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
                                    # add edge to graph with 'async' attribute
                                    graph.edge(node, node2, style='dashed', label=edge_label, link_type='async')
                                else:
                                    graph.edge(node, node2, label=edge_label,link_type='sync')

                                # add to active nodes if not already there
                                if node not in active_nodes_names:
                                    active_nodes_names.append(node)
                                if node2 not in active_nodes_names:
                                    active_nodes_names.append(node2)

    # for each node, setting display attributes: box and assigned color
    for node_name in active_nodes_names:
        graph.node(node_name,shape='box',style='filled', fillcolor=nodes_dict[node_name]['color'])

    # output graph settings
    graph.body.append('rankdir=LR')

    # generate graph file as svg
    output_path = Path().resolve() / output_directory
    graph.render(output_path / 'umsg_graph', view=False, format='svg')

    hovermap = create_hovermap(graph)

    update_svg(hovermap, output_path / 'umsg_graph.svg')


def create_hovermap(graph):
    # determine which nodes and edges should be displayed when hovering over each node
    # for async links, the depth search is 1
    # for sync links, we search untill the end of the graph

    # go through each edge by searching the graph body text untill no '->' is found
    nodes_list = []
    edges_list = []
    for line in graph.body:
        if '->' in line:
            # split line into tokens
            tokens = line.split(' ')

            # extract node names, remove \t and \n
            node1 = tokens[0].replace('\t', '').replace('\n', '')
            node2 = tokens[2].replace('\t', '').replace('\n', '')

            if node1 not in nodes_list:
                nodes_list.append(node1)
            if node2 not in nodes_list:
                nodes_list.append(node2)

            # find link_type=attribute in string
            link_type = re.findall(r'link_type=\w+', line)[0].split('=')[1]

            edges_list.append({'from':node1,'to': node2,'link_type':link_type})

    # for each node, build a list of nodes and edges to display when hovering over it
    # use the index values from nodes_list and edges_list
    hovermap = {}
    # add number of nodes and edges to the hovermap
    hovermap['length'] = ({'n_nodes':len(nodes_list), 'n_edges':len(edges_list)})

    # add map for each node
    hovermap['maps'] = []
    for idx, node in enumerate(nodes_list):
        hovermap['maps'].append({'nodes':[], 'edges':[]})

        # go through all edges, if node is in edge, add the other node to the list
        for edge in edges_list:
            if node == edge['from']:
                hovermap['maps'][idx]['nodes'].append(nodes_list.index(edge['to']))
                hovermap['maps'][idx]['edges'].append(edges_list.index(edge))
            elif node == edge['to']:
                hovermap['maps'][idx]['nodes'].append(nodes_list.index(edge['from']))
                hovermap['maps'][idx]['edges'].append(edges_list.index(edge))
        # add the node itself to the list
        hovermap['maps'][idx]['nodes'].append(idx)

        # remove duplicates
        hovermap['maps'][idx]['nodes'] = list(dict.fromkeys(hovermap['maps'][idx]['nodes']))
        hovermap['maps'][idx]['edges'] = list(dict.fromkeys(hovermap['maps'][idx]['edges']))

    return hovermap


def update_svg(hovermap,file_path):
    # create hovermap json
    hovermap_json = json.dumps(hovermap)
    snippet = "<script type='text/javascript'><![CDATA["
    snippet += "var hovermap = " + hovermap_json + ";"
    snippet += "hovermap.maps.forEach(function(e,t){let n=`node${t+1}`;document.getElementById(n).addEventListener('mouseover',function(){for(let e=0;e<hovermap.length.n_nodes;e++)hovermap.maps[t].nodes.includes(e)?document.getElementById(`node${e+1}`).style.opacity=1:document.getElementById(`node${e+1}`).style.opacity=.2;for(let n=0;n<hovermap.length.n_edges;n++)hovermap.maps[t].edges.includes(n)?document.getElementById(`edge${n+1}`).style.opacity=1:document.getElementById(`edge${n+1}`).style.opacity=.2}),document.getElementById(n).addEventListener('mouseout',function(){for(let e=0;e<hovermap.length.n_nodes;e++)document.getElementById(`node${e+1}`).style.opacity=1;for(let t=0;t<hovermap.length.n_edges;t++)document.getElementById(`edge${t+1}`).style.opacity=1})});"
    snippet += "]]></script>"

    # add snippet at end of file, before </svg> tag
    with open(file_path, 'r') as file:
        filedata = file.read()
    filedata = filedata.replace('</svg>', snippet + '\n</svg>')
    with open(file_path, 'w') as file:
        file.write(filedata)



    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', dest='source_directories', required=True)
    parser.add_argument('-c', dest='colors', required=False)
    parser.add_argument('-o', dest='output_directory', required=True)

    args = parser.parse_args()
    graph = create_graph(args.source_directories, args.colors, args.output_directory)
