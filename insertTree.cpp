#include "insertTree.h"

void insertNode(Node* root, int targetDepth) {
    std::cout << "���Ϊ " << targetDepth << " �Ľڵ���������:" << std::endl;
    printNodesAtDepth(root, targetDepth); // �ٶ� printNodesAtDepth �����Ѿ�����

    std::cout << "��ѡ��һ������������������: ";
    char parentDomain[100];
    std::cin >> parentDomain;

    Node* parentNode = findNodeAtDepth(root, parentDomain, targetDepth); // �ٶ� findNodeAtDepth �Ѷ���
    if (parentNode) {
        std::cout << "��������Ҫ���������: ";
        char newDomain[100];
        std::cin >> newDomain;

        char* reversedDomain = reverseDomainParts(newDomain); // �ٶ� reverseDomainParts �Ѷ���
        createHelper(parentNode, reversedDomain, parentNode->depth);
        std::cout << "��������ɹ���" << std::endl;

        // ��ӡ�²���ڵ������·��
        Node* newNode = parentNode->firstChild; // �ٶ��ղ�����ǵ�һ���ӽڵ�
        printFullDomainPath(newNode);

        delete[] reversedDomain;
    }
}

