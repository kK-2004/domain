#include "deleteDomain.h"

void deleteNodeAndSubtree(Node* root, Node* target) {
    if (root == nullptr) {
        return;
    }
    if (root == target) {
        // �ͷ�Ŀ��ڵ㼰������
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
        // ɾ��Ŀ��ڵ㼰������
        deleteNodeAndSubtree(root, node);
        std::cout << "ɾ���ɹ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ��ò���������Ӧ�Ľڵ㡣" << std::endl;
    }
}

