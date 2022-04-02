//
// Created by 猿木 on 2022/4/1.
//

#include "Csv.h"

void Csv::setFileName(std::string filename) {
    _filename = filename;
}

std::string Csv::getFileName() {
    return _filename;
}
