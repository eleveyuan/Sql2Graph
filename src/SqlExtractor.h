//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLEXTRACTOR_H
#define SQL2GRAPH_SQLEXTRACTOR_H

#include "MySqlParserBaseVisitor.h"
//#include "MySqlParserVisitor.h"

#include "Csv.h"

class SqlExtractor: public MySqlParserBaseVisitor {
public:
    /**
     * create 区块
     */
    virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
        csv.setFileName(ctx->tableName()->getText());
        std::cout << ctx->tableName()->getText() << std::endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
        std::cout << ctx->uid()->getText() << std::endl;
        return visitChildren(ctx);
    }

    Csv csv;

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
