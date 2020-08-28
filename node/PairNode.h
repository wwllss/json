//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_PAIRNODE_H
#define HIJSON_PAIRNODE_H


#include <utility>

#include "ValueNode.h"
#include "StringNode.h"

class PairNode : public ValueNode {

public:
    StringNode *key;
    ValueNode *value;

    explicit PairNode(StringNode *key, ValueNode *value);

    std::string toString() override;
};

#endif //HIJSON_PAIRNODE_H
