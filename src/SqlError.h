//
// Created by 猿木 on 2022/3/31.
//

#ifndef SQL2GRAPH_SQLERROR_H
#define SQL2GRAPH_SQLERROR_H

#include <string>

class SqlError {
public
    string Stack = "";
    string Symbol = "";
    string Msg = "";
    string Exce = "";
    string File = "";
};


#endif //SQL2GRAPH_SQLERROR_H
