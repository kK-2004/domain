#include "insertTree.h"

void insertNode(Node* root, int targetDepth)
{
    std::cout << "深度为 " << targetDepth << " 的节点域名如下:" << std::endl;
    printNodesAtDepth(root, targetDepth);

    std::cout << "请选择一个域名（输入域名）: ";
    char parentDomain[100];
    std::cin >> parentDomain;

    Node* parentNode = findNodeAtDepth(root, parentDomain, targetDepth);
    if (parentNode) {
        std::cout << "请输入需要插入的域名: ";
        char newDomain[100];
        std::cin >> newDomain;

        char* reversedDomain = reverseDomainParts(newDomain);
        createHelper(parentNode, reversedDomain, parentNode->depth);
        std::cout << "域名插入成功！" << std::endl;
    }
    //////缺少匹配错误的判断
}
