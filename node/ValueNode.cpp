//
// Created by 张远 on 2020/8/28.
//

#include "ValueNode.h"

std::string ValueNode::toString() {
    return "unknown";
}

std::string ValueNode::description() {
    return description(0);
}

std::string ValueNode::description(int level) {
    return description(level, toString());
}

std::string ValueNode::description(int level, const std::string &str) {
    std::string desc;
    for (int i = 0; i < level; ++i) {
        desc += "\t";
    }
    desc += str;
    return desc;
}
