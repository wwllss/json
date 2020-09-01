//
// Created by 张远 on 2020/8/27.
//

#include <iostream>
#include "Lexer.h"

Lexer::Lexer(std::istream *is) : is(is) {
    consume();
}

Token *Lexer::nextToken() {
    while (c != EOF) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                consume();
                continue;
            case '{':
                consume();
                return new Token(TokenType::LEFT_PARENT, "{");
            case '}':
                consume();
                return new Token(TokenType::RIGHT_PARENT, "}");
            case '[':
                consume();
                return new Token(TokenType::LEFT_BRACE, "[");
            case ']':
                consume();
                return new Token(TokenType::RIGHT_BRACE, "]");
            case ',':
                consume();
                return new Token(TokenType::COMMA, ",");
            case '=':
                consume();
                return new Token(TokenType::EQUALS, "=");
            case ':':
                consume();
                return new Token(TokenType::COLON, ":");
            case '"':
                return matchString();
            case 't':
                return matchTrue();
            case 'f':
                return matchFalse();
            case 'n':
                return matchNull();
            default:
                if (c == '-' || isDigit(c)) {
                    return matchNumber();
                }

                throw std::runtime_error(&"Unknown Character"[c]);
        }
    }
    return new Token(TokenType::EOF_CHAR, "<EOF>");
}

char Lexer::consume() {
    p++;
    char pre = c;
    c = is->get();
    return pre;
}

char Lexer::match(char x) {
    if (x == c) {
        return consume();
    }
    std::string errMsg = "Not matched ";
    errMsg += std::string(1, x);
    errMsg += "(";
    errMsg += std::string(1, c);
    errMsg += ")";
    throw std::runtime_error(errMsg);
}

std::string Lexer::match(std::string str) {
    for (std::string::iterator i = str.begin(); i < str.end(); ++i) {
        match(*i);
    }
    return str;
}

std::string Lexer::match(const std::function<bool(char)> &fn, int count) {
    char chars[count];
    for (int i = 0; i < count; ++i) {
        if (fn(c)) {
            chars[i] = consume();
        } else {
            throw std::runtime_error(&"Not matched "[c]);
        }
    }
    return std::string(chars);
}

Token *Lexer::matchString() {
    match('"');
    std::string chars = matchChars();
    match('"');
    return new Token(TokenType::STRING, chars);
}

std::string Lexer::matchChars() {
    std::string str;
    while (c != '"') {
        if (c == '\\') {
            consume();
            switch (c) {
                case '"':
                    consume();
                    str += "\"";
                    break;
                case '\\':
                    consume();
                    str += "\\";
                    break;
                case '/':
                    consume();
                    str += "/";
                    break;
                case 'b':
                    consume();
                    str += "\b";
                    break;
                case 'f':
                    consume();
                    str += "\f";
                    break;
                case 't':
                    consume();
                    str += "\t";
                    break;
                case 'n':
                    consume();
                    str += "\n";
                    break;
                case 'r':
                    consume();
                    str += "\r";
                    break;
                case 'u':
                    consume();
                    str += "u";
                    str += matchUnicode();
                    break;
                default:
                    throw std::runtime_error(&"Error Character in std::string: "[c]);
            }
        } else {
            str += std::string(1, consume());
        }
    }
    return str;
}

std::string Lexer::matchUnicode() {
    std::string str;
    str.append(match(isDigit, 4));
    return str;
}

Token *Lexer::matchTrue() {
    return new Token(TokenType::TRUE, match("true"));
}

Token *Lexer::matchFalse() {
    return new Token(TokenType::FALSE, match("false"));
}

Token *Lexer::matchNumber() {
    std::string str;
    if (c == '-') {
        str += std::string(1, consume());
    }
    if (c == '0') {
        str += std::string(1, consume());
    } else {
        str += matchDigits();
    }
    if (c == '.') {
        str += match(".");
        str += matchDigits();
    }
    if (c == 'e' || c == 'E') {
        auto fn = [](char x) { return x == 'e' || x == 'E'; };
        str += match(fn, 1);
        if (c == '+' || c == '-') {
            str += std::string(1, consume());
        }
        str += matchDigits();
    }
    return new Token(TokenType::NUMBER, str);
}

std::string Lexer::matchDigits() {
    std::string str;
    while (isDigit(c)) {
        str += match(isDigit, 1);
    }
    return str;
}

Token *Lexer::matchNull() {
    return new Token(TokenType::Null, match("null"));
}

bool Lexer::isDigit(char x) {
    return x >= '0' && x <= '9';
}

bool Lexer::isHexDigit(char x) {
    return isDigit(x)
           || (x >= 'a' && x <= 'f')
           || (x >= 'A' && x <= 'F');
}
