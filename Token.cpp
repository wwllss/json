//
// Created by 张远 on 2020/9/9.
//

#include "Token.h"

#include <utility>

Token::Token(TokenType tokenType, std::string text) : tokenType(tokenType), text(std::move(text)) {}

std::string Token::toString() const {
    std::string str;
    str += "<Token:";
    switch (tokenType) {
        case EOF_CHAR:
            str += "EOF_CHAR";
            break;
        case UNKNOWN:
            str += "UNKNOWN";
            break;
        case LEFT_PARENT:
            str += "LEFT_PARENT";
            break;
        case RIGHT_PARENT:
            str += "RIGHT_PARENT";
            break;
        case LEFT_BRACE:
            str += "LEFT_BRACE";
            break;
        case RIGHT_BRACE:
            str += "RIGHT_BRACE";
            break;
        case COMMA:
            str += "COMMA";
            break;
        case EQUALS:
            str += "EQUALS";
            break;
        case COLON:
            str += "COLON";
            break;
        case STRING:
            str += "STRING";
            break;
        case NUMBER:
            str += "NUMBER";
            break;
        case TRUE:
            str += "TRUE";
            break;
        case FALSE:
            str += "FALSE";
            break;
        case Null:
            str += "Null";
            break;
    };
    str += " Text:";
    str += text;
    str += ">";
    return str;
}
