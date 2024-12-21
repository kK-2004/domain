#include "createTree.h"

void createHelper(Node* node, const char* domain, int depth)
{
    const char* remainingDomain = strchr(domain, '.');

    size_t partLength = (remainingDomain == nullptr) ? strlen(domain) : remainingDomain - domain;
    char* part = new char[partLength + 1];
    strncpy(part, domain, partLength);
    part[partLength] = '\0';

    Node* child = node->firstChild;
    while (child) {
        if (strcmp(child->name, part) == 0) {
            delete[] part;
            if (remainingDomain == nullptr) return;
            createHelper(child, remainingDomain + 1, depth + 1);
            return;
        }
        child = child->nextSibling;
    }

    Node* newNode = new Node(part, depth + 1);  // 设置新节点的深度
    newNode->nextSibling = node->firstChild;
    node->firstChild = newNode;

    delete[] part;
    if (remainingDomain != nullptr) {
        createHelper(newNode, remainingDomain + 1, depth + 1);
    }

}
