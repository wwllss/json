//
// Created by 张远 on 2020/8/28.
//

#include "StringNode.h"

StringNode::StringNode(Token *token) : token(token) {}

std::string StringNode::toString() {
    return "<String: " + token->text + ">";
}