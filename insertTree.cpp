#include "insertTree.h"

void insertNode(Node* root, int targetDepth)
{
    std::cout << "���Ϊ " << targetDepth << " �Ľڵ���������:" << std::endl;
    printNodesAtDepth(root, targetDepth);

    std::cout << "��ѡ��һ������������������: ";
    char parentDomain[100];
    std::cin >> parentDomain;

    Node* parentNode = findNodeAtDepth(root, parentDomain, targetDepth);
    if (parentNode) {
        std::cout << "��������Ҫ���������: ";
        char newDomain[100];
        std::cin >> newDomain;

        char* reversedDomain = reverseDomainParts(newDomain);
        createHelper(parentNode, reversedDomain, parentNode->depth);
        std::cout << "��������ɹ���" << std::endl;
    }
    //////ȱ��ƥ�������ж�
}
