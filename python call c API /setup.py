#! usr/bin/python
#coding=utf-8 
from distutils.core import setup, Extension
example_mod = Extension('example', sources = ['fact.c'])
setup(name = "exmple",
    version = "1.0",
    description = "A sample extension module",
    ext_modules = [example_mod], #setup()中，只有这行是必须的
)