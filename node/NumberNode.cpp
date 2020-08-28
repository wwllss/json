//
// Created by 张远 on 2020/8/28.
//

#include "NumberNode.h"

NumberNode::NumberNode(Token *token) : token(token) {}

std::string NumberNode::toString() {
    return "<Number: " + token->text + ">";
}