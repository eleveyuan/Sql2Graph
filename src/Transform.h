//
// Created by 猿木 on 2022/6/9.
//

#ifndef SQL2GRAPH_TRANSFORM_H
#define SQL2GRAPH_TRANSFORM_H

#include <string>

class Transform {
public:
    std::string sql;
    std::string db_type;

    void check();

    void toGraph();
    void toCSV();

private:
    std::string sql_type;
};


#endif //SQL2GRAPH_TRANSFORM_H
