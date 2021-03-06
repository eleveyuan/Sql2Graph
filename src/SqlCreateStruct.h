//
// Created by eleve on 4/4/22.
//

#ifndef SQL2GRAPH_SQLCREATESTRUCT_H
#define SQL2GRAPH_SQLCREATESTRUCT_H

#include <string>
#include <vector>

class SqlCreateStruct {
public:
    std::string tableName;

    class Entity;

    class Entity {
    public:
        std::string columnName;
        std::string columnType;
        std::string commentStr;
        Entity() = default;
        Entity(const Entity& e) {
            columnName = e.columnName;
            columnType = e.columnType;
            commentStr = e.commentStr;
        }
        ~Entity() = default;
    };

    std::vector<Entity> entitys;

    std::string getTableName() {
        return tableName;
    }

    void setTableName(std::string _tablename) {
        tableName = _tablename;
    }

    void appendEntity(Entity _entity) {
        entitys.push_back(_entity);
    }

};


#endif //SQL2GRAPH_SQLCREATESTRUCT_H
