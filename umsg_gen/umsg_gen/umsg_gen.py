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
    args = parser.parse_args()

    # create full paths
    msg_def_path = Path().resolve() / args.msgs_directory
    output_path = Path().resolve() / args.output_directory
    templates_path = Path(__file__).resolve().parent / 'templates'
    core_path = Path(__file__).resolve().parent / 'core'

    # setup jinja2 environment & templates
    env = Environment(loader=FileSystemLoader(templates_path))
    env.trim_blocks = True
    env.lstrip_blocks = True
    inc_template = env.get_template(name='msg.h.j2')
    src_template = env.get_template(name='msg.c.j2')
    cmake_template = env.get_template(name='CMakeLists.txt.j2')

    # find all topic json files
    files = glob.glob(f'{msg_def_path}\*.json')

    # if files list is empty return error
    if not files:
        print('No files found')
        exit(1)

    # generate source and header files for each topic json file

    # delete output directory if it exists
    if output_path.exists():
        shutil.rmtree(output_path)
    sources = []
    for file in files:
        # load topic json file
        f = open(file)
        topic_dict = json.load(f)

        # add name field to topic dict
        topic_dict['name'] = Path(file).stem

        # generate header
        filename = f'{output_path}/inc/umsg_{topic_dict["name"]}.h'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = inc_template.render(topic_dict=topic_dict,date=datetime.date.today())
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)

        #generate source
        filename = f'{output_path}/src/{topic_dict["name"]}.c'
        Path(filename).parent.mkdir(parents=True, exist_ok=True)
        content = src_template.render(topic_dict=topic_dict, date=datetime.date.today())
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)

        # add file name to list
        sources.append(Path(filename).name)

    # Gereate cmake file
    content = cmake_template.render(sources=sources, date=datetime.date.today())
    filename = f'{output_path}/CMakeLists.txt'
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)

    # copy core library to output using shutil
    shutil.copytree(core_path, output_path / 'core')

if __name__ == "__main__":
    main()