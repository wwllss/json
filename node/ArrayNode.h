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


#endif //HIJSON_ARRAYNODE_H
