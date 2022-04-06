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
            Item(const Item &obj) {
                this->columnName = obj.columnName;
                this->columnType = obj.columnType;
                this->commentStr = obj.commentStr;
            }
            ~Item() {}
        };

        Item *item = new Item();
        std::vector<Item>* items;

        void appendItem(Item *_item) {
            Item tmp = *_item;
            items->push_back(tmp);
        }

        void showItems() {
            std::cout << "table name: " << tableName << std::endl;
            for (std::vector<Item>::iterator iter = items->begin(); iter != items->end(); iter++) {
                std::cout << iter->columnName << " "
                          << iter->columnType << " "
                          << iter->commentStr << " "
                          << std::endl;
            }
        }

        virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            // sqlCreateStruct.setTableName(ctx->tableName()->getText());
            tableName = ctx->tableName()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
            item->columnName = ctx->uid()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
            item->columnType = ctx->dataType()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
            item->commentStr = ctx->STRING_LITERAL()->getText();
            appendItem(item);
            return visitChildren(ctx);
        }

    };

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
