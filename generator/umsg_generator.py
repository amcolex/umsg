from jinja2 import Environment, FileSystemLoader
import json
import glob

max_score = 100
test_name = "Python Challenge"
students = [
    {"name": "Sandrine",  "score": 100},
    {"name": "Gergeley", "score": 87},
    {"name": "Frieda", "score": 92},
]

environment = Environment(loader=FileSystemLoader("templates/"))
environment.trim_blocks = True
environment.lstrip_blocks = True
inc_template = environment.get_template("msg_inc.j2")
src_template = environment.get_template("msg_src.j2")

# Opening JSON file
files = glob.glob('msg_def\*.json')

for file in files:
    print(file)
    f = open(file)
    topic_dict = json.load(f)

    # generate header
    filename = f'out/{topic_dict["name"]}.h'
    content = inc_template.render(topic_dict=topic_dict)
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)

    #generate source
    filename = f'out/{topic_dict["name"]}.c'
    content = src_template.render(topic_dict=topic_dict)
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(content)