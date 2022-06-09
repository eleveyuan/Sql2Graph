//
// Created by 猿木 on 2022/4/1.
//

#ifndef SQL2GRAPH_CSV_H
#define SQL2GRAPH_CSV_H

#include <string>

class Csv {
private:
    std::string _filename;
public:
    Csv() = default;
    void setFileName(std::string filename);
    std::string getFileName();

    virtual void toCSV() = 0;
};


#endif //SQL2GRAPH_CSV_H
