import os.path as osp

from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc

cpp_args = ['-std=c++11']

py_inc = get_python_inc()

ext_modules = [
    Extension(
        'wrap',
        ['code.cpp'],
        include_dirs=[py_inc, osp.join(py_inc, '../eigen3')],
        language='c++',
        extra_compile_args=cpp_args,
    ),
]

setup(
    name='wrap',
    version='0.0.1',
    author='Chris Choy',
    author_email='chrischoy@ai.stanford.edu',
    description='Example',
    ext_modules=ext_modules,
)
