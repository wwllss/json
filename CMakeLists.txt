cmake_minimum_required(VERSION 3.17)
project(HiJson)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        HiJson
        main.cpp
        Lexer.cpp
        Lexer.h
        Token.h
        TokenType.h
        Parser.cpp
        Parser.h
        node/ValueNode.h
        node/StringNode.h
        node/NullNode.h
        node/TrueNode.h
        node/FalseNode.h
        node/PairNode.h
        node/ObjectNode.h
        node/ArrayNode.h
        node/NumberNode.h node/ValueNode.cpp node/TrueNode.cpp node/StringNode.cpp node/PairNode.cpp node/ObjectNode.cpp node/NumberNode.cpp node/NullNode.cpp node/FalseNode.cpp node/ArrayNode.cpp)