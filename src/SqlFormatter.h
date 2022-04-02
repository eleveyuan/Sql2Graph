//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLFORMATTER_H
#define SQL2GRAPH_SQLFORMATTER_H

#include <string>
#include <algorithm>

#include "MySqlLexer.h"
#include "MySqlParser.h"
#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include "ParseTreeWalker.h"

#include "SqlExtractor.h"

class SqlFormatter {
public:
    std::string toUpperCase(std::string sql);  // antlr4语法下要求mysql语句是大写
    void parserSql(const std::string &sql);
};


#endif //SQL2GRAPH_SQLFORMATTER_H
