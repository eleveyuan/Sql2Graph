#include <iostream>
#include <string>

#include "SqlFormatter.h"

int main() {
    std::string a = "CREATE TABLE IF NOT EXISTS runoob_tbl (\n"
                    "   `runoob_id` INT UNSIGNED AUTO_INCREMENT,\n"
                    "   `runoob_title` VARCHAR(100) NOT NULL COMMENT '名称',\n"
                    "   `runoob_author` VARCHAR(40) NOT NULL,\n"
                    "   `submission_date` DATE,\n"
                    "   PRIMARY KEY ( `runoob_id` )\n"
                    ")ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    std::string type = "mysql";
    SqlFormatter sf;
    a = sf.toUpperCase(a);
    sf.parserSql(a);
    return 0;
}