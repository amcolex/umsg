from pathlib import Path
import argparse
import glob
import re
import graphviz

def create_graph(source_directories, colors, output_directory):

    directories_list = source_directories.split(';')
    if colors is not None:
        colors_list = colors.split(';')

        # check that directories and colors are the same length
        if len(directories_list) != len(colors_list):
            print('Error: number of directories and colors must be the same')
            return

    # create dictionary for all files
    files_dict = {}
    for index, directory in enumerate(directories_list):
        directory_path = Path().resolve() / directory
        print(directory_path)

        # find all *.c source files recursively
        files = glob.glob(str(directory_path) + '/**/*.c', recursive=True)

        for file in files:
            f = open(file)
            print(file)

            # find strings following the template umsg_topic_message_api(parameters)
            instances = re.findall(r'(?<=umsg_)\w+(?=\()', f.read())
            f.close()

            # add file name to dict
            file_name = Path(file).stem

            # extract as topic_msg_api
            for instance in instances:
                params = instance.split('_')
                # add key words to files_dict
                if file_name not in files_dict:
                    files_dict[file_name] = {'functions' : [], 'color' : colors_list[index]}	
                files_dict[file_name]['functions'].append(params)

    # create graph
    graph = graphviz.Digraph(comment='uMsg Graph')

    # list of nodes which contain links to other nodes
    active_nodes = []	
    # create edges between nodes wich share a message, from 'publish' to 'receive' or 'peek'
    for file in files_dict:
        for instance in files_dict[file]['functions']:
            for file2 in files_dict:
                for instance2 in files_dict[file2]['functions']:
                    if instance[1] == instance2[1] and instance[2] == 'publish' and (instance2[2] == 'receive' or instance2[2] == 'peek'):
                        # add node to list if not already in it
                        if file not in active_nodes:
                            active_nodes.append({'file': file, 'color': files_dict[file]['color']})
                        # add graph edge dashed. if peek, add dashed edge
                        if instance2[2] == 'peek':
                            graph.edge(file, file2, style='dashed', label=instance[0]+'.'+instance[1])
                        else:
                            graph.edge(file, file2, label=instance[0]+'.'+instance[1])
                        break

    # for each node, setting display attributes
    for node in active_nodes:
        graph.node(node['file'],shape='box')
        graph.node(node['file'],style='filled', fillcolor=node['color'])

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
