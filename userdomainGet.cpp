#include "userdomainGet.h"
#include "tools.h"
#include <iostream>
#include <cstring>

// ����·�����Էָ����������Ӵ�����
int countSubstrings(const char* str, char delimiter) {
    int count = 0;
    while (*str) {
        if (*str == delimiter) {
            count++;
        }
        str++;
    }
    return count + 1;  // �Ӵ����� = �ָ������� + 1
}

// �洢·���ĺ���
void storeValidPath(char validPaths[MAX_PATHS][MAX_PATH_LEN], int& validPathCount, const char* path) {
    if (validPathCount < MAX_PATHS) {
        strncpy(validPaths[validPathCount], path, MAX_PATH_LEN - 1);
        validPaths[validPathCount][MAX_PATH_LEN - 1] = '\0';  // ȷ���ַ����� '\0' ��β
        validPathCount++;
    }
}

void printSubtreeUser(Node* node, char* path, int depth, char* user, char validPaths[MAX_PATHS][MAX_PATH_LEN], int& validPathCount) {
    // ȷ���ڵ����
    if (!node) return;

    // ���浱ǰ��ȣ����ڻָ� path
    int currentDepth = depth;

    // �����Ⱥ��û�ƥ��
    if (node->name && strlen(node->name) > 0) {
        bool shouldAddNode = (depth < 2) || (node->id && strcmp(node->id, user) == 0);

        if (shouldAddNode) {
            int len = strlen(node->name);
            if (depth > 0) {
                path[depth] = '.';  // ��ӷָ��� '.'
                depth++;
            }
            strncpy(path + depth, node->name, len);  // ƴ�ӵ�ǰ�ڵ�����
            depth += len;
            path[depth] = '\0';  // ȷ���ַ����� '\0' ��β

            // ������·��
            if (path[0] != '\0') {
                char* reversedPath = reverseDomainParts(path);
                int substrCount = countSubstrings(reversedPath, '.');
                if (substrCount >= 2) {
                    storeValidPath(validPaths, validPathCount, reversedPath);  // �洢����������·��
                }
                delete[] reversedPath;
            }
        }
    }

    // �ݹ��ӡ�ӽڵ�
    printSubtreeUser(node->firstChild, path, depth, user, validPaths, validPathCount);

    // �ݹ��ӡ�ֵܽڵ㣬�ָ����
    printSubtreeUser(node->nextSibling, path, currentDepth, user, validPaths, validPathCount);
}

// ��ӡ������Ч·��
void printValidPaths(char validPaths[MAX_PATHS][MAX_PATH_LEN], int validPathCount) {
    for (int i = 0; i < validPathCount; i++) {
        std::cout << validPaths[i] << std::endl;
    }
}
