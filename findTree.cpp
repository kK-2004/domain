#include "findTree.h"


Node* findExactNode(Node* node, const char* domain)
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
            if (remainingDomain == nullptr) {
                return child;
            }
            return findExactNode(child, remainingDomain + 1);
        }
        child = child->nextSibling;
    }
    delete[] part;
    return nullptr;
}

void findVagueNode(Node* root, const char* domain)
{
    char* reversedDomain = reverseDomainParts(domain);

    Node* node = findExactNode(root, reversedDomain);
    if (node) {
        char* path = removeSubdomain(node->name, domain);
        printf("%s\n", path);
        std::cout << "�Ӹýڵ㿪ʼ�������ṹ���£�" << std::endl;
        printSubtreeReversed(node, path, strlen(path));
    }
    else {
        std::cout << "δ�ҵ��ò���������Ӧ�Ľڵ㡣" << std::endl;
    }
}
