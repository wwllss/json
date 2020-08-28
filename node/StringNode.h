//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_STRINGNODE_H
#define HIJSON_STRINGNODE_H

#include "ValueNode.h"
#include "../Token.h"

class StringNode : public ValueNode {

public:
    Token *token;

    explicit StringNode(Token *token);

    std::string toString() override;

};

#endif //HIJSON_STRINGNODE_H
