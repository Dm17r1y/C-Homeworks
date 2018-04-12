from distutils.core import setup, Extension

requires = []
ext_kwargs = {}

module1 = Extension('counter', sources = ['python-api.c'])

setup (name = 'counter',
       version = '1.0',
       description = 'count links module',
       ext_modules = [module1])
