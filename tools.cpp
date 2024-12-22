#include "tools.h"

// ������������ȥ�����������ֲ�����ʣ�ಿ��
char* removeSubdomain(const char* subdomain, const char* fullDomain) {
    size_t subdomainLength = strlen(subdomain);

    // ���ǰ׺�Ƿ�ƥ����ƥ�䲿�ֺ������һ��'.'
    if (strncmp(subdomain, fullDomain, subdomainLength) == 0 &&
        fullDomain[subdomainLength] == '.') {
        // ��ȡʣ�ಿ��
        const char* remaining = fullDomain + subdomainLength + 1; // ����'.'
        char* result = new char[strlen(remaining) + 1];
        strcpy(result, remaining);
        return result;
    }

    // �����ƥ�䣬���ؿ��ַ���
    char* emptyResult = new char[1];
    emptyResult[0] = '\0';
    return emptyResult;
}

// ��ת�������ֲ����ط�ת����ַ���
char* reverseDomainParts(const char* input) {
    size_t len = strlen(input);
    char* mutableInput = new char[len + 1];
    strcpy(mutableInput, input);

    char* result = new char[len + 1];
    char* tempResult = result;

    char* token = strtok(mutableInput, ".");
    char* parts[100];
    int partCount = 0;

    while (token != nullptr) {
        parts[partCount++] = token;
        token = strtok(nullptr, ".");
    }

    for (int i = partCount - 1; i >= 0; --i) {
        if (i != partCount - 1) {
            *tempResult++ = '.';
        }
        strcpy(tempResult, parts[i]);
        tempResult += strlen(parts[i]);
    }

    delete[] mutableInput;

    return result;
}


void printSubtreeReversed(Node* node, char* path, int depth) {
    // ȷ���ڵ����
    if (!node) return;

    // ���浱ǰ��ȣ����ڻָ� path
    int currentDepth = depth;

    // ȷ���ڵ�������Ч
    if (node->name && strlen(node->name) > 0) {
        int len = strlen(node->name);
        if (depth > 0) {
            path[depth] = '.';  // ��ӷָ��� '.'
            depth++;
        }
        strncpy(path + depth, node->name, len);  // ƴ�ӵ�ǰ�ڵ�����
        depth += len;
        path[depth] = '\0';  // ȷ���ַ����� '\0' ��β
    }

    // ��ӡ��ǰ·��������
    if (path[0] != '\0') {  // ȷ��·���ǿ�
        char* reversedPath = reverseDomainParts(path);
        std::cout << reversedPath << std::endl;
        delete[] reversedPath;
    }

    // �ݹ��ӡ�ӽڵ�
    printSubtreeReversed(node->firstChild, path, depth);

    // �ݹ��ӡ�ֵܽڵ㣬�ָ����
    printSubtreeReversed(node->nextSibling, path, currentDepth);
}


void printNodesAtDepth(Node* node, int targetDepth) {
    if (!node) return;

    if (node->depth == targetDepth) {
        std::cout << node->name << "\n";
    }

    printNodesAtDepth(node->firstChild, targetDepth);
    printNodesAtDepth(node->nextSibling, targetDepth);
}

Node* findNodeAtDepth(Node* node, const char* name, int targetDepth) {
    if (!node) return nullptr;

    if (node->depth == targetDepth && strcmp(node->name, name) == 0) {
        return node;
    }

    Node* result = findNodeAtDepth(node->firstChild, name, targetDepth);
    if (result) return result;

    return findNodeAtDepth(node->nextSibling, name, targetDepth);
}

