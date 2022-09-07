from jinja2 import Environment, FileSystemLoader
import json
import glob
import argparse
import os
import pathlib

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', dest='msgs_directory', required=True)
    parser.add_argument('-o', dest='output_directory', required=True)
    args = parser.parse_args()

    msg_def_path = pathlib.Path().resolve() / args.msgs_directory
    output_path = pathlib.Path().resolve() / args.output_directory
    templates_path = pathlib.Path(__file__).resolve().parent / 'templates'

    env = Environment(loader=FileSystemLoader(templates_path))
    env.trim_blocks = True
    env.lstrip_blocks = True
    inc_template = env.get_template(name='msg_inc.j2')
    src_template = env.get_template(name='msg_src.j2')

    # Opening JSON file
    files = glob.glob(f'{msg_def_path}\*.json')

    for file in files:
        print(f'generating {file}...')
        f = open(file)
        topic_dict = json.load(f)

        # generate header
        filename = f'{output_path}/{topic_dict["name"]}.h'
        os.makedirs(os.path.dirname(filename),exist_ok=True)
        content = inc_template.render(topic_dict=topic_dict)
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)

        #generate source
        filename = f'{output_path}/{topic_dict["name"]}.c'
        os.makedirs(os.path.dirname(filename),exist_ok=True)
        content = src_template.render(topic_dict=topic_dict)
        with open(filename, mode="w", encoding="utf-8") as message:
            message.write(content)