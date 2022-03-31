# Sql2Graph
面对较长的sql难以招架，对sql进行解析，返回其主要结构图

## 预备知识
1. 大数据组件的sql层基本都是使用Antlr4来进行语法设计,例如：hive/presto/spark
2. Antlr4设计使用监听者/访问者模式，可以很快上手
3. Antlr4提供了Jetbrain平台相关的插件，解析g4语法文件，生成相应的监听器/访问器文件。


其实Antlr4很好的与java结合，这里使用c++进行开发，存粹是个人偏爱c/c++，作为练手。 
最后用python作为胶水打包c++所写的功能。

## 注意事项

### 添加antlr4-cpp-runtime
在 [cpp-target](https://github.com/antlr/antlr4/blob/master/doc/cpp-target.md#where-can-i-get-the-runtime) 中提到需要下载编译运行时环境：
```
Once you've generated the lexer and/or parser code, you need to download or build the runtime.
```
从 [antlr4 download](https://www.antlr.org/download.html) 官网下载c++运行时环境
将其中的runtime/src拷贝出来即可通过编译。


## 主要用法(todo)

check_sql(sql: str, cate: str): 检查sql语句

parser_sql(sql: str): 解析sql语句

dml2json(sql: str): 解析dml语句为json格式

save_img(path: str): 将sql语句转为graph保存

convert_ddl(sql: str, from: str, to: str): 将建表语句从现在的语法转为目标语法

ddl2csv(sql: str, path: str): 将建表语句转为csv格式
