#!/bin/bash
set -o errexit

LOCATION=antlr-4.9.3-complete.jar
java -jar $LOCATION -Dlanguage=Cpp -listener -visitor -o generated/mysql/ resource/mysql/MySqlLexer.g4 resource/mysql/MySqlParser.g4

