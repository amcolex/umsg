from setuptools import setup
import os

version_str = os.getenv('RELEASE_VERSION')

setup(
    name='umsg-gen',
    version=version_str,
    author="Alex Pabouctsidis",
    author_email='alex.pabouct@gmail.com',
    url='https://github.com/Amcolex/umsg_gen.git',
    description = "Code generator for the μMsg pub-sub c library",
    long_description="Generates the full μMsg library code from JSON message definitions.",
    py_modules=['umsg_gen'],
    packages=['umsg_gen'],
    include_package_data=True,
    install_requires=[
        'jinja2',
    ],
    entry_points='''
        [console_scripts]
        umsg-gen=umsg_gen.umsg_gen:main
    ''',
)