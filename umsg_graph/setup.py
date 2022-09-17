from setuptools import setup
import os

version_str = os.getenv('RELEASE_VERSION')

setup(
    name='umsg-graph',
    version=version_str,
    author="Alex Pabouctsidis",
    author_email='alex.pabouct@gmail.com',
    url='https://github.com/Amcolex/umsg.git',
    description = "μMsg communication graph generator",
    long_description="Generates a graphviz graph of μMsg communication links between modules",
    py_modules=['umsg_graph'],
    packages=['umsg_graph'],
    include_package_data=True,
    install_requires=[
        'graphviz',
    ],
    entry_points='''
        [console_scripts]
        umsg-graph=umsg_graph.umsg_graph:main
    ''',
)