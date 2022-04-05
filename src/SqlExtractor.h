//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLEXTRACTOR_H
#define SQL2GRAPH_SQLEXTRACTOR_H

#include "MySqlParserBaseVisitor.h"

#include <string>
#include <vector>

class SqlExtractor {
public:
    class SqlCreateVisitor;

    class SqlCreateVisitor: public MySqlParserBaseVisitor {
    public:
        std::string tableName;
        class Item;

        class Item {
        public:
            std::string columnName;
            std::string columnType;
            std::string commentStr;
            Item() = default;
        };

        Item item;
        std::vector<Item> *items;

        /**
         * create block
         */
        virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            // sqlCreateStruct.setTableName(ctx->tableName()->getText());
            tableName = ctx->tableName()->getText();
            return visitChildren(ctx);
        }

        /**
         * column name
         */
        virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
            item.columnName = ctx->uid()->getText();
            return visitChildren(ctx);
        }

        /**
         * column type
         */
        virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
            item.columnType = ctx->dataType()->getText();
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
            item.commentStr = ctx->STRING_LITERAL()->getText();
            return visitChildren(ctx);
        }

    };

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
