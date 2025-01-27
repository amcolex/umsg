from jinja2 import Environment, FileSystemLoader
import json
import glob
import argparse
import datetime
from pathlib import Path
import shutil

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', dest='msgs_directory', required=True)
    parser.add_argument('-o', dest='output_directory', required=True)
    parser.add_argument('-l', '--logging', action='store_true')
    args = parser.parse_args()
    # create full paths
    msg_def_path = Path().resolve() / args.msgs_directory
    output_path = Path().resolve() / args.output_directory
    logger_output_path = Path().resolve() / args.output_directory / 'log_parser'
    templates_path = Path(__file__).resolve().parent / 'templates'
    core_path = Path(__file__).resolve().parent / 'core'
    
    if args.logging ==True:
        log = "do_log"
    else:
        log = "no_log"


    # setup jinja2 environment & templates
    env = Environment(loader=FileSystemLoader(templates_path))
    env.trim_blocks = True
    env.lstrip_blocks = True
    
    msg_class_inc_template = env.get_template(name='msg_classes.h.j2')
    msg_class_src_template = env.get_template(name='msg_classes.c.j2')
    log_parser_template = env.get_template(name='log_parser.cpp.j2')
    cmake_log_parser_template = env.get_template(name='CMakeLists_log_parser.txt.j2')
    inc_template = env.get_template(name='msg.h.j2')
    src_template = env.get_template(name='msg.c.j2')
    cmake_template = env.get_template(name='CMakeLists.txt.j2')

    # find all topic json files
    files = glob.glob(f'{msg_def_path}/*.json')

    # if files list is empty return error
    if not files:
        print('No files found')
        exit(1)
    # generate source and header files for each topic json file

    # delete output directory if it exists
    if output_path.exists():
        shutil.rmtree(output_path)
    sources = []
    headers = []
    topic_dict_list = []
    for file in files:
        # load topic json file
        f = open(file)
        topic_dict = json.load(f)
        # add name field to topic dict
        topic_dict['name'] = Path(file).stem
        topic_dict_list.append(topic_dict)
        
        # generate header
        filename = f'{output_path}/inc/umsg_{topic_dict["name"]}.h'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = inc_template.render(topic_dict=topic_dict,date=datetime.date.today(),log=log)
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)

        #generate source
        filename = f'{output_path}/src/{topic_dict["name"]}.c'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = src_template.render(topic_dict=topic_dict, date=datetime.date.today(),log=log)
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)

        # add file name to list
        sources.append(Path(filename).name)
        headers.append(f'{topic_dict["name"]}')
 

    # Generate the msg_classes header file
    content = msg_class_inc_template.render(topic_dict_list = topic_dict_list, date=datetime.date.today())
    filename = f'{output_path}/inc/umsg_classes.h'
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)


    content = msg_class_src_template.render(topic_dict_list = topic_dict_list, date=datetime.date.today())
    filename = f'{output_path}/src/umsg_classes.c'
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)



    if log == "do_log":
        #Generate the logfile parser
        filename = f'{output_path}/log_parser/log_parser.cpp'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = log_parser_template.render(topic_dict_list=topic_dict_list, date=datetime.date.today())
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)
        #Generate the Cmake for the logfile parser
        filename = f'{output_path}/log_parser/CMakeLists.txt'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = cmake_log_parser_template.render(topic_dict_list=topic_dict_list, date=datetime.date.today())
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)



    # Gereate cmake file
    content = cmake_template.render(sources=sources, date=datetime.date.today())
    filename = f'{output_path}/CMakeLists.txt'
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)

    # copy core library to output using shutil
    shutil.copytree(core_path, output_path / 'core')

if __name__ == "__main__":
    main()
