#!/bin/bash
set -o errexit

LOCATION=antlr-4.9.3-complete.jar
# -Xexact-output-dir for issue(https://github.com/antlr/antlr4/issues/638 and https://github.com/antlr/antlr4/pull/2065)
java -jar $LOCATION -Dlanguage=Cpp -listener -visitor -Xexact-output-dir -o generated/mysql/ resource/mysql/MySqlLexer.g4 resource/mysql/MySqlParser.g4

