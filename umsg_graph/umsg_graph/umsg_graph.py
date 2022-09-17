from pathlib import Path
import argparse
import glob
import re
import graphviz

def create_graph(source_directory, output_directory):

    directory_path = Path().resolve() / source_directory
    output_path = Path().resolve() / output_directory

    print(directory_path)

    # find all source files
    files = glob.glob(f'{directory_path}\*.c')

    # if files list is empty return error
    if not files:
        print('No files found')
        exit(1)

    # create dictory for all files
    files_dict = {}
    for file in files:
        f = open(file)
        print(file)

        # add file name to dict
        file_name = Path(file).stem

        # find strings following the template umsg_topic_message_api(parameters)
        instances = re.findall(r'(?<=umsg_)\w+(?=\()', f.read())
        f.close()

        # extract as topic_msg_api
        for instance in instances:
            params = instance.split('_')
            # add key words to files_dict
            if file_name not in files_dict:
                files_dict[file_name] = []
            files_dict[file_name].append(params)

    # create graph
    graph = graphviz.Digraph(comment='uMsg Graph')

    # list of nodes which contain links to other nodes
    nodes = []
    # create edges between nodes wich share a message, from 'publish' to 'receive' or 'peek'
    for file in files_dict:
        for instance in files_dict[file]:
            for file2 in files_dict:
                for instance2 in files_dict[file2]:
                    if instance[1] == instance2[1] and instance[2] == 'publish' and (instance2[2] == 'receive' or instance2[2] == 'peek'):
                        # add node to list if not already in it
                        if file not in nodes:
                            nodes.append(file)
                        # add graph edge dashed. if peek, add dashed edge
                        if instance2[2] == 'peek':
                            graph.edge(file, file2, style='dashed', label=instance[0]+'.'+instance[1])
                        else:
                            graph.edge(file, file2, label=instance[0]+'.'+instance[1])
                        break

    # for each node, setting display attributes
    for node in nodes:
        graph.node(node,shape='box')

    # output graph settings
    graph.body.append('rankdir=LR')

    # generate graph file as svg
    graph.render(output_path / 'umsg_graph', view=True, format='svg')


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', dest='source_directory', required=True)
    parser.add_argument('-o', dest='output_directory', required=True)

    args = parser.parse_args()
    create_graph(args.source_directory, args.output_directory)
