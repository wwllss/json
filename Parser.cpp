//
// Created by 张远 on 2020/8/28.
//

#include "Parser.h"

Parser::Parser(Laxer *laxer) : laxer(laxer) {
    consume();
}

ValueNode *Parser::parse() {
    ValueNode *root = parseValue();
    return root;
}

void Parser::consume() {
    head = laxer->nextToken();
}

Token *Parser::match(TokenType tt) {
    if (is(tt)) {
        auto token = head;
        consume();
        return token;
    }
    return nullptr;
//    throw std::runtime_error("Not matched Token " + std::to_string(tt));
}

bool Parser::is(TokenType tt) const {
    return tt == head->tokenType;
}

ValueNode *Parser::parseValue() {
    if (is(TokenType::LEFT_PARENT)) {
        return parseObject();
    }
    if (is(TokenType::LEFT_BRACE)) {
        return parseArray();
    }
    if (is(TokenType::STRING)) {
        return parseString();
    }
    if (is(TokenType::NUMBER)) {
        return parseNumber();
    }
    if (is(TokenType::TRUE)) {
        return parseTrue();
    }
    if (is(TokenType::FALSE)) {
        return parseFalse();
    }
    if (is(TokenType::Null)) {
        return parseNull();
    }
    if (is(TokenType::EOF_CHAR)) {
        return nullptr;
    }
    throw std::runtime_error("unknown TypeToken");
}

ObjectNode *Parser::parseObject() {
    auto *objectNode = new ObjectNode;
    match(TokenType::LEFT_PARENT);
    while (!is(TokenType::RIGHT_PARENT)) {
        if (match(TokenType::COMMA)) {
            continue;
        }
        StringNode *key = parseString();
        match(TokenType::COLON);
        ValueNode *value = parseValue();
        objectNode->pairs[key] = value;
    }
    match(TokenType::RIGHT_PARENT);
    return objectNode;
}

ArrayNode *Parser::parseArray() {
    auto *arrayNode = new ArrayNode;
    match(TokenType::LEFT_BRACE);
    while (!is(TokenType::RIGHT_BRACE)) {
        if (match(TokenType::COMMA)) {
            continue;
        }
        arrayNode->elements.push_back(parseValue());
    }
    match(TokenType::RIGHT_BRACE);
    return arrayNode;
}

StringNode *Parser::parseString() {
    return new StringNode(match(TokenType::STRING));
}

NumberNode *Parser::parseNumber() {
    return new NumberNode(match(TokenType::NUMBER));
}

TrueNode *Parser::parseTrue() {
    match(TokenType::TRUE);
    return new TrueNode;
}

FalseNode *Parser::parseFalse() {
    match(TokenType::FALSE);
    return new FalseNode;
}

NullNode *Parser::parseNull() {
    match(TokenType::Null);
    return new NullNode;
}
