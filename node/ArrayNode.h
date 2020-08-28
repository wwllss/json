//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_ARRAYNODE_H
#define HIJSON_ARRAYNODE_H


#include <vector>
#include "ValueNode.h"

class ArrayNode : public ValueNode {

public:
    std::vector<ValueNode*> elements;

    std::string toString() override;

    std::string description(int level) override;

};

std::string ArrayNode::toString() {
    std::string str;
    str += "<Array: ";
    for (auto &element : elements) {
        str += element->toString();
    }
    str += ">";
    return str;
}

std::string ArrayNode::description(int level) {
    std::string desc;
    desc += ValueNode::description(level, "<Array: [");
    for (auto &element : elements) {
        desc += element->description(level + 1);
    }
    desc += ValueNode::description(level, ">");
    return desc;
}


#endif //HIJSON_ARRAYNODE_H
