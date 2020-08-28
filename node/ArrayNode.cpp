//
// Created by 张远 on 2020/8/28.
//

#include "ArrayNode.h"

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
    desc += ValueNode::description(level, "<Array: [\n");
    for (auto &element : elements) {
        desc += element->description(level + 1);
        desc += "\n";
    }
    desc += ValueNode::description(level, "]>");
    return desc;
}