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


#endif //HIJSON_OBJECTNODE_H
