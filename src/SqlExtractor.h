//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLEXTRACTOR_H
#define SQL2GRAPH_SQLEXTRACTOR_H

#include <string>
#include <vector>

#include "MySqlParserBaseVisitor.h"

#include "SqlCreateStruct.h"

class SqlExtractor {
public:
    class SqlCreateVisitor;

    class SqlCreateVisitor: public MySqlParserBaseVisitor {
    public:
        SqlCreateStruct item;
        SqlCreateStruct::Entity entity;

        void appendItem(SqlCreateStruct::Entity &_item) {
            SqlCreateStruct::Entity tmp = _item;
            std::cout << &tmp << " - " << &_item << std::endl;
            item.appendEntity(tmp); // SIGSEGV problem
        }

        void showItems() {
            std::cout << "table name: " << item.tableName << std::endl;
            for (auto iter = item.entitys.begin(); iter != item.entitys.end(); iter++) {
                std::cout << iter->columnName << " "
                          << iter->columnType << " "
                          << iter->commentStr << " "
                          << std::endl;
            }
        }

        virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            // sqlCreateStruct.setTableName(ctx->tableName()->getText());
            item.setTableName(ctx->tableName()->getText());
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
            entity.columnName = ctx->uid()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
            entity.columnType = ctx->dataType()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
            entity.commentStr = ctx->STRING_LITERAL()->getText();
            appendItem(entity);
            return visitChildren(ctx);
        }

        ~SqlCreateVisitor() { }

    };

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
