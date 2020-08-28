//
// Created by 张远 on 2020/8/28.
//

#include "PairNode.h"

PairNode::PairNode(StringNode *key, ValueNode *value) : key(key), value(value) {}

std::string PairNode::toString() {
    return "<Pair: " + key->toString() + " => " + value->toString() + ">";
}