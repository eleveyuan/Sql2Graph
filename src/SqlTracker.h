//
// Created by 猿木 on 2022/4/17.
//

#ifndef SQL2GRAPH_SQLTRACKER_H
#define SQL2GRAPH_SQLTRACKER_H

#include "MySqlParserBaseListener.h"

#include "SqlCreateStruct.h"

class SqlTracker {
public:
    class SqlCreateListenor;
    class SqlCreateListenor: public MySqlParserBaseListener {
    public:
        SqlCreateStruct item;
        SqlCreateStruct::Entity entity;  // 破坏了nesed class的封装

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

        virtual void enterColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            item.setTableName(ctx->tableName()->getText());
        }
        virtual void exitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            appendItem(entity);
        }

        virtual void enterColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
            entity.columnName = ctx->uid()->getText();
        }
        virtual void exitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override { }

        virtual void enterColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
            entity.columnType = ctx->dataType()->getText();
        }
        virtual void exitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override { }

        virtual void enterCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
            entity.commentStr = ctx->STRING_LITERAL()->getText();
        }
        virtual void exitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override { }
    };
};


#endif //SQL2GRAPH_SQLTRACKER_H
