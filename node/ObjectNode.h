//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_OBJECTNODE_H
#define HIJSON_OBJECTNODE_H


#include <map>
#include "ValueNode.h"
#include "StringNode.h"
#include "PairNode.h"

class ObjectNode : public ValueNode {

public:
    std::map<StringNode *, ValueNode *> pairs;

    std::string toString() override;

    std::string description(int level) override;
};

std::string ObjectNode::toString() {
    std::string str;
    std::map<StringNode *, ValueNode *>::iterator iterator;
    for (iterator = pairs.begin(); iterator != pairs.end(); iterator++) {
        auto *pairNode = new PairNode(iterator->first, iterator->second);
        str += pairNode->toString();
    }
    return str;
}

std::string ObjectNode::description(int level) {
    std::string desc;
    desc += ValueNode::description(level, "<Object: {\n>");
    std::map<StringNode *, ValueNode *>::iterator iterator;
    for (iterator = pairs.begin(); iterator != pairs.end(); iterator++) {
        StringNode *key = iterator->first;
        ValueNode *value = iterator->second;
        desc += key->description(level + 1);
        desc += " =\n";
        desc += value->description(level + 2);
        desc += "\n";
    }
    desc += ValueNode::description(level, "}>");
    return desc;
}


#endif //HIJSON_OBJECTNODE_H
