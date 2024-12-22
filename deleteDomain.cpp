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
        // �ͷ�Ŀ��ڵ㼰������
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
        std::cout << "ɾ���ɹ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ��ò���������Ӧ�Ľڵ㡣" << std::endl;
    }
}