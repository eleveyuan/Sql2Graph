#!/usr/bin/env python
# -*- coding: utf-8 -*-
from setuptools import setup, find_packages

with open('README.md', encoding='utf-8') as readme_file:
    readme = readme_file.read()

setup(
    name='Sql2Graph',
    version='0.1.0',
    packages=find_packages(),
    author="eleve yuan",
    author_email="eleveyuan@gmail.com",
    url="https://github.com/eleveyuan/Sql2Graph",
)