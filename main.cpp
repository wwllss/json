#include <iostream>
#include "Parser.h"

int main() {

    std::ifstream is;
    is.open("/Users/zhangyuan/Workspace/C/Test1/files/detail.json");

    /*Token *token;

    while ((token = laxer.nextToken())->tokenType != TokenType::EOF_CHAR) {
        printf("%s", token->toString().c_str());
        printf("\n");
    }*/

    Parser parser(new Laxer(&is));
    ValueNode *root = parser.parse();
    printf("%s", root->description().c_str());

    return 0;
}
