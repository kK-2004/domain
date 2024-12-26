#include "deleteDomain.h"

void deleteNodeAndSubtree(Node* root, Node* target) {
    if (root == nullptr) {
        return;
    }
    if (root == target) {
        // 释放目标节点及其子树
        root = nullptr;
        return;
    }
    if (root->firstChild == target) {
        root->firstChild = target->nextSibling;
    }
    else if (root->nextSibling == target) {
        root->nextSibling = target->nextSibling;
    }
    deleteNodeAndSubtree(root->firstChild, target);
    deleteNodeAndSubtree(root->nextSibling, target);
}
void deleteDomain(Node* root, const char* domain)
{
    char* reversedDomain = reverseDomainParts(domain);
    Node* node = findExactNode(root, reversedDomain);
    if (node) {
        // 删除目标节点及其子树
        deleteNodeAndSubtree(root, node);
        std::cout << "删除成功" << std::endl;
    }
    else {
        std::cout << "未找到该部分域名对应的节点。" << std::endl;
    }
}

