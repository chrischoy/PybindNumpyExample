from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc

cpp_args = ['-std=c++11']

ext_modules = [
    Extension(
        'wrap',
        ['code.cpp'],
        include_dirs=[get_python_inc()],
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
