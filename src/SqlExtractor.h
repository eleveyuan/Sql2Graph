//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLEXTRACTOR_H
#define SQL2GRAPH_SQLEXTRACTOR_H

#include <string>
#include <vector>
#include <fstream>

#include "MySqlParserBaseVisitor.h"
#include "SqlCreateStruct.h"
#include "Csv.h"

class SqlExtractor {
public:
    class SqlCreateVisitor;

    class SqlCreateVisitor: public MySqlParserBaseVisitor, public Csv {
    public:
        SqlCreateStruct item;
        SqlCreateStruct::Entity *entity = new SqlCreateStruct::Entity();  // 破坏了nesed class的封装

        void appendItem(SqlCreateStruct::Entity &_item) {
            SqlCreateStruct::Entity tmp = _item;
            std::cout << &tmp << " - " << &_item << std::endl;
            item.appendEntity(tmp); // SIGSEGV problem
            _item.columnName = ' ';
            _item.columnType = ' ';
            _item.commentStr = ' ';
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

        void toCSV() {
            setFileName(item.tableName);
            std::ofstream ofs(item.tableName + ".csv");
            if (!ofs.is_open()) {
                std::cerr << "Error opening file for saving csv file." << std::endl;
                exit(EXIT_FAILURE);
            }
            for (auto iter = item.entitys.begin(); iter != item.entitys.end(); iter++) {
                ofs << iter->columnName << ","
                    << iter->columnType << ","
                    << iter->commentStr << ","
                    << std::endl;
            }
            ofs.close();
        }

        virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
            // sqlCreateStruct.setTableName(ctx->tableName()->getText());
            item.setTableName(ctx->tableName()->getText());
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
            entity->columnName = ctx->uid()->getText();
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
            entity->columnType = ctx->dataType()->getText();
            // little tricky, 个人不知道这一行为是否安全, 需要后续验证 TODO
            // 加入vector, 但是commentSr还没访问到，但是对象已经生成，后续visit会将commentStr的地址填上相应的数据
            appendItem(*entity);
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
            entity->commentStr = ctx->STRING_LITERAL()->getText();
            return visitChildren(ctx);
        }

        ~SqlCreateVisitor() { }

    };

};


#endif //SQL2GRAPH_SQLEXTRACTOR_H
