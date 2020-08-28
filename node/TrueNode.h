//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_TRUENODE_H
#define HIJSON_TRUENODE_H


#include "ValueNode.h"

class TrueNode : public ValueNode {

    std::string toString() override;

};

#endif //HIJSON_TRUENODE_H
