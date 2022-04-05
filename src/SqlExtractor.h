//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLEXTRACTOR_H
#define SQL2GRAPH_SQLEXTRACTOR_H

#include "MySqlParserBaseVisitor.h"
//#include "MySqlParserVisitor.h"

#include "Csv.h"
#include "SqlCreateStruct.h"

class SqlExtractor: public MySqlParserBaseVisitor {
public:
    /**
     * create block
     */
    virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
        sqlCreateStruct.setTableName(ctx->tableName()->getText());
        return visitChildren(ctx);
    }

    /**
     * column name
     */
    virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {

        std::cout << std::endl << ctx->uid()->getText() << std::endl;
        return visitChildren(ctx);
    }

    /**
     * column type
     */
    virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
        std::cout << ctx->dataType()->getText();
        return visitChildren(ctx);
    }

    /**
     * column constraints
     */
    virtual antlrcpp::Any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *ctx) override {
        std::cout << "\t" << ctx->nullNotnull()->getText() << std::endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *ctx) override {
        std::cout << ctx->DEFAULT()->getText() << " ";
        std::cout << ctx->defaultValue()->getText() << std::endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *ctx) override {
        std::cout << ctx->PRIMARY()->getText() << " " << ctx->KEY()->getText()
                  << std::endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *ctx) override {
        std::cout << ctx->UNIQUE()->getText() << " " << ctx->KEY()->getText()
                  << std::endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
        std::cout << ctx->COMMENT()->getText() << " " << ctx->STRING_LITERAL()->getText()
                  << std::endl;
        return visitChildren(ctx);
    }

    SqlCreateStruct sqlCreateStruct;
    Csv csv;

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
