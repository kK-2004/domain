#include "deleteDomain.h"

void deleteSubtree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteSubtree(node->firstChild);
    deleteSubtree(node->nextSibling);
    delete node;
}
void deleteNodeAndSubtree(Node* root, Node* target) {
    if (root == nullptr) {
        return;
    }
    if (root == target) {
        // 释放目标节点及其子树
        deleteSubtree(target);
        return;
    }
    if (root->firstChild == target) {
        root->firstChild = nullptr;
    }
    else if (root->nextSibling == target) {
        root->nextSibling = nullptr;
    }
    deleteNodeAndSubtree(root->firstChild, target);
    deleteNodeAndSubtree(root->nextSibling, target);
}
void deleteDomain(Node* root, const char* domain)
{
    char* reversedDomain = reverseDomainParts(domain);
    Node* node = findExactNode(root, reversedDomain);
    if (node) {
        char* deletepath = removeSubdomain(node->name, domain);
        Node* deletenode = findExactNode(root, reverseDomainParts(deletepath));
        deleteNodeAndSubtree(root, node);
        std::cout << "删除成功" << std::endl;
    }
    else {
        std::cout << "未找到该部分域名对应的节点。" << std::endl;
    }
}