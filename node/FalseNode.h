//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_FALSENODE_H
#define HIJSON_FALSENODE_H


#include "ValueNode.h"

class FalseNode : public ValueNode {

    std::string toString() override;

};

std::string FalseNode::toString() {
    return "<False>";
}


#endif //HIJSON_FALSENODE_H
