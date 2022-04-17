//
// Created by 猿木 on 2022/3/31.
//
#include "SqlFormatter.h"

std::string SqlFormatter::toUpperCase(std::string sql) {
    transform(sql.begin(), sql.end(), sql.begin(), ::toupper);
    return sql;
}

void SqlFormatter::parserSql(const std::string &sql) {
    antlr4::ANTLRInputStream input(sql);
    MySqlLexer lexer(&input);  // 解析词法
    antlr4::CommonTokenStream tokens(&lexer);  // 转化为token
    MySqlParser parser(&tokens);  // 解析语法
    parser.setBuildParseTree(true);
    MySqlParser::RootContext *tree = parser.root(); // 语法树root节点

//    SqlExtractor::SqlCreateVisitor ev;
//    ev.visit(tree);
//    ev.showItems();
    SqlTracker::SqlCreateListenor *ev = new SqlTracker::SqlCreateListenor();
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(ev, tree);
    ev->showItems();
}