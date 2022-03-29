# Sql2Graph
面对较长的sql难以招架，对sql进行解析，返回其主要结构图

## 预备知识
1. 大数据组件的sql层基本都是使用Antlr4来进行语法设计,例如：hive/presto/spark
2. Antlr4设计使用监听者/访问者模式，可以很快上手
3. Antlr4提供了Jetbrain平台相关的插件，解析g4语法文件，生成相应的监听器/访问器文件。


其实Antlr4很好的与java结合，这里使用c++进行开发，存粹是个人偏爱c/c++，作为练手。 最用python作为胶水打包。
