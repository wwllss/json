//
// Created by 张远 on 2020/8/27.
//

#ifndef HIJSON_TOKENTYPE_H
#define HIJSON_TOKENTYPE_H

enum TokenType {
    EOF_CHAR = -1,
    UNKNOWN = 0,
    LEFT_PARENT = 1,
    RIGHT_PARENT = 2,
    LEFT_BRACE = 3,
    RIGHT_BRACE = 4,
    COMMA = 5,
    EQUALS = 6,
    COLON = 7,
    STRING = 8,
    NUMBER = 9,
    TRUE = 10,
    FALSE = 11,
    Null = 12
};

#endif //HIJSON_TOKENTYPE_H
