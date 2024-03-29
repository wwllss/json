//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_NUMBERNODE_H
#define HIJSON_NUMBERNODE_H

#include "ValueNode.h"
#include "../Token.h"

class NumberNode : public ValueNode {

private:
    Token *token;

public:
    explicit NumberNode(Token *token);

    std::string toString() override;

};

#endif //HIJSON_NUMBERNODE_H
