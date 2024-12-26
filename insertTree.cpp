#include "insertTree.h"

void insertNode(Node* root, int targetDepth) {
    std::cout << "深度为 " << targetDepth << " 的节点域名如下:" << std::endl;
    printNodesAtDepth(root, targetDepth); // 假定 printNodesAtDepth 函数已经定义

    std::cout << "请选择一个域名（输入域名）: ";
    char parentDomain[100];
    std::cin >> parentDomain;

    Node* parentNode = findNodeAtDepth(root, parentDomain, targetDepth); // 假定 findNodeAtDepth 已定义
    if (parentNode) {
        std::cout << "请输入需要插入的域名: ";
        char newDomain[100];
        std::cin >> newDomain;

        char* reversedDomain = reverseDomainParts(newDomain); // 假定 reverseDomainParts 已定义
        createHelper(parentNode, reversedDomain, parentNode->depth);
        std::cout << "域名插入成功！" << std::endl;

        // 打印新插入节点的完整路径
        Node* newNode = parentNode->firstChild; // 假定刚插入的是第一个子节点
        printFullDomainPath(newNode);

        delete[] reversedDomain;
    }
}

