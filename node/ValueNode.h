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

#endif //HIJSON_VALUENODE_H
