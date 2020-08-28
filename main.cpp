#include <iostream>
#include "Parser.h"

int main() {

    std::ifstream is;
    is.open("/Users/zhangyuan/Workspace/C/HiJson/files/detail.json");

    Laxer laxer(&is);

    /*Token *token;

    while ((token = laxer.nextToken())->tokenType != TokenType::EOF_CHAR) {
        printf("%s", token->toString().c_str());
        printf("\n");
    }*/

    Parser parser(laxer);
    ValueNode *root = parser.parse();
    printf("%s", root->description().c_str());

    return 0;
}
