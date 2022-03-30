#include <iostream>
#include <string>

#include "MysqlParser.h"
#include "MysqlLexer.h"

using namespace antlr4;
using namespace std;

int main() {
    string a = "SELECT A, B FROM TB C;";
    cout << a << endl;
    return 0;
}