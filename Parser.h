//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_PARSER_H
#define HIJSON_PARSER_H


#include "Laxer.h"
#include "node/ValueNode.h"
#include "node/ObjectNode.h"
#include "node/ArrayNode.h"
#include "node/TrueNode.h"
#include "node/FalseNode.h"
#include "node/NumberNode.h"
#include "node/NullNode.h"

class Parser {

private:
    Laxer laxer;
    Token *head = nullptr;

public:
    explicit Parser(const Laxer &laxer);

    ValueNode *parse();

private:
    void consume();

    Token *match(TokenType tt);

    bool is(TokenType tt) const;

    ValueNode *parseValue();

    ObjectNode *parseObject();

    ArrayNode *parseArray();

    StringNode *parseString();

    NumberNode *parseNumber();

    TrueNode *parseTrue();

    FalseNode *parseFalse();

    NullNode *parseNull();
};


#endif //HIJSON_PARSER_H
