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
            keywords = instance.split('_')
            # add key words to files_dict
            if file_name not in files_dict:
                files_dict[file_name] = []
            files_dict[file_name].append(keywords)

    # create graph
    graph = graphviz.Digraph(comment='uMsg Graph')
    # for each file create a node
    for file in files_dict:
        graph.node(file, file)
    
    # create a single edge between nodes with share the same message
    for file in files_dict:
        for msg in files_dict[file]:
            for file2 in files_dict:
                if file != file2:
                    for msg2 in files_dict[file2]:
                        if msg[1] == msg2[1]:
                            graph.edge(file, file2, msg[0]+'.'+msg[1])
                            break
    # generate dot file
    graph.render(output_path / 'umsg_graph', view=True)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', dest='source_directory', required=True)
    parser.add_argument('-o', dest='output_directory', required=True)

    args = parser.parse_args()
    create_graph(args.source_directory, args.output_directory)
