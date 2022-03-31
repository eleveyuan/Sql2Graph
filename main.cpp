#include <iostream>
#include <string>

#include "SqlFormatter.h"

int main() {
    std::string a = "select a, b from tb";
    SqlFormatter sf;
    std::cout << sf.toUpperCase(a) << std::endl;
    sf.parserSql(a);
    return 0;
}