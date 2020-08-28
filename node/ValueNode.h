//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_VALUENODE_H
#define HIJSON_VALUENODE_H


#include <string>

class ValueNode {

public:
    virtual std::string toString();

    virtual std::string description();

    virtual std::string description(int level);

    static std::string description(int level, const std::string &str);

};

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


#endif //HIJSON_VALUENODE_H
