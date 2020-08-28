//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_STRINGNODE_H
#define HIJSON_STRINGNODE_H


#include <utility>

#include "ValueNode.h"
#include "../Token.h"

class StringNode : public ValueNode {

public:
    Token *token;

    explicit StringNode(Token *token);

    std::string toString() override;

};

StringNode::StringNode(Token *token) : token(token) {}

std::string StringNode::toString() {
    return "<String: " + token->text + ">";
}


#endif //HIJSON_STRINGNODE_H
