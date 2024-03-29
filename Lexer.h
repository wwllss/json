//
// Created by 张远 on 2020/8/27.
//

#ifndef HIJSON_LEXER_H
#define HIJSON_LEXER_H


#include <string>
#include <fstream>
#include "Token.h"

class Lexer {

private:
    std::istream *is;
    char c = EOF;

public:
    explicit Lexer(std::istream *is);

    Token* nextToken();

private:
    char consume();

    char match(char x);

    std::string match(std::string str);

    std::string match(const std::function<bool(char)> &fn, int count);

    std::string matchChars();

    std::string matchUnicode();

    Token* matchString();

    Token* matchTrue();

    Token* matchFalse();

    Token* matchNumber();

    std::string matchDigits();

    Token* matchNull();

    static bool isDigit(char x);

    static bool isHexDigit(char x);

};


#endif //HIJSON_LEXER_H
