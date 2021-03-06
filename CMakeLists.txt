cmake_minimum_required(VERSION 3.14)
project(Sql2Graph)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/generated
        ${PROJECT_SOURCE_DIR}/generated/mysql
        ${PROJECT_SOURCE_DIR}/libs
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/misc
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/atn
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/dfa
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/tree
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/support
)

set(src_dir
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlLexer.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParser.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserVisitor.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserListener.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/SqlError.h
        ${PROJECT_SOURCE_DIR}/src/SqlFormatter.h
        ${PROJECT_SOURCE_DIR}/src/SqlFormatter.cpp
        ${PROJECT_SOURCE_DIR}/src/SqlExtractor.cpp
        ${PROJECT_SOURCE_DIR}/src/SqlExtractor.h
        ${PROJECT_SOURCE_DIR}/src/Csv.cpp
        ${PROJECT_SOURCE_DIR}/src/Csv.h
        ${PROJECT_SOURCE_DIR}/src/SqlCreateStruct.cpp
        ${PROJECT_SOURCE_DIR}/src/SqlCreateStruct.h src/SqlTracker.cpp src/SqlTracker.h src/utils.cpp src/utils.h src/Transform.cpp src/Transform.h)

file(GLOB antlr4-cpp-src
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/atn/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/dfa/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/misc/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/support/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/tree/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/tree/pattern/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime/src/tree/xpath/*.cpp
)
add_library(antlr4-runtime ${antlr4-cpp-src})
add_executable(Sql2Graph ${src_dir} main.cpp)
target_link_libraries(Sql2Graph antlr4-runtime)  # 将目标文件与库文件进行链接
