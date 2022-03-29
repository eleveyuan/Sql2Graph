cmake_minimum_required(VERSION 3.14)
project(Sql2Graph)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/generated
        ${PROJECT_SOURCE_DIR}/generated/mysql
        ${PROJECT_SOURCE_DIR}/libs
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3
)

set(src_dir
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlLexer.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParser.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserVisitor.cpp
        ${PROJECT_SOURCE_DIR}/generated/mysql/MySqlParserBaseVisitor.cpp
)

file(GLOB antlr4-cpp-src
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/atn/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/dfa/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/misc/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/support/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/tree/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/tree/pattern/*.cpp
        ${PROJECT_SOURCE_DIR}/libs/antlr4-cpp-runtime-4.9.3/run/usr/local/include/antlr4-runtime/tree/xpath/*.cpp
)
add_library(antlr4-cpp-runtime ${antlr4-cpp-src})
add_executable(Sql2Graph ${src_dir} main.cpp)
target_link_libraries(Sql2Graph antlr4-cpp-runtime)  # 将目标文件与库文件进行链接
