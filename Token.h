//
// Created by 张远 on 2020/8/27.
//

#ifndef HIJSON_TOKEN_H
#define HIJSON_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {

public:
    TokenType tokenType;
    std::string text;

    Token(TokenType tokenType, std::string text);

    std::string toString() const;
};

#endif //HIJSON_TOKEN_H
