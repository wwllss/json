//
// Created by 张远 on 2020/8/27.
//

#ifndef HIJSON_TOKEN_H
#define HIJSON_TOKEN_H


#include <string>
#include "TokenType.h"

/*std::string TokenType2String(TokenType tokenType) {
    switch (tokenType) {
        case EOF_CHAR:
            return "EOF_CHAR";
        case UNKNOWN:
            return "UNKNOWN";
        case LEFT_PARENT:
            return "LEFT_PARENT";
        case RIGHT_PARENT:
            return "RIGHT_PARENT";
        case LEFT_BRACE:
            return "LEFT_BRACE";
        case RIGHT_BRACE:
            return "RIGHT_BRACE";
        case COMMA:
            return "COMMA";
        case EQUALS:
            return "EQUALS";
        case COLON:
            return "COLON";
        case STRING:
            return "STRING";
        case NUMBER:
            return "NUMBER";
        case BOOLEAN:
            return "BOOLEAN";
        case Null:
            return "Null";
    }
}*/

class Token {

public:
    TokenType tokenType;
    std::string text;

    Token(TokenType tokenType, const std::string &text) {
        this->tokenType = tokenType;
        this->text = text;
    }

    std::string toString() const {
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
};

#endif //HIJSON_TOKEN_H
