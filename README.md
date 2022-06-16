# Sql2Graph
面对较长的sql难以招架，对sql进行解析，返回其主要结构图

## 预备知识
1. 大数据组件的sql层基本都是使用Antlr4来进行语法设计,例如：hive/presto/spark
2. Antlr4设计使用监听者/访问者模式，可以很快上手
3. Antlr4社区提供了较多语法文件，不需要额外编写语法文件
4. Antlr4提供了Jetbrain平台相关的插件，解析g4语法文件，生成相应的监听器/访问器文件。


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


## 解析语法文件
1. 解析语法文件，可以在clion安装使用antlr4的插件，进行辅助生成
2. 或可运行gen.sh命令进行生成
``` shell
/bin/bash gen.sh
```


## 主要用法(todo)

1. ddl to csv (done)
2. restructure code  (doing)
3. dml to json (todo)
4. dml to graph (todo)
