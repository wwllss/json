//
// Created by 张远 on 2020/8/28.
//

#ifndef HIJSON_NULLNODE_H
#define HIJSON_NULLNODE_H

#include "ValueNode.h"

class NullNode : public ValueNode {

    std::string toString() override;

};


#endif //HIJSON_NULLNODE_H
