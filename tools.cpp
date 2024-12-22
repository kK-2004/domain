#include "tools.h"

// 从完整域名中去掉子域名部分并返回剩余部分
char* removeSubdomain(const char* subdomain, const char* fullDomain) {
    size_t subdomainLength = strlen(subdomain);

    // 检查前缀是否匹配且匹配部分后紧接着一个'.'
    if (strncmp(subdomain, fullDomain, subdomainLength) == 0 &&
        fullDomain[subdomainLength] == '.') {
        // 提取剩余部分
        const char* remaining = fullDomain + subdomainLength + 1; // 跳过'.'
        char* result = new char[strlen(remaining) + 1];
        strcpy(result, remaining);
        return result;
    }

    // 如果不匹配，返回空字符串
    char* emptyResult = new char[1];
    emptyResult[0] = '\0';
    return emptyResult;
}

// 反转域名部分并返回反转后的字符串
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
    // 确保节点存在
    if (!node) return;

    // 保存当前深度，用于恢复 path
    int currentDepth = depth;

    // 确保节点名称有效
    if (node->name && strlen(node->name) > 0) {
        int len = strlen(node->name);
        if (depth > 0) {
            path[depth] = '.';  // 添加分隔符 '.'
            depth++;
        }
        strncpy(path + depth, node->name, len);  // 拼接当前节点名称
        depth += len;
        path[depth] = '\0';  // 确保字符串以 '\0' 结尾
    }

    // 打印当前路径（倒序）
    if (path[0] != '\0') {  // 确保路径非空
        char* reversedPath = reverseDomainParts(path);
        std::cout << reversedPath << std::endl;
        delete[] reversedPath;
    }

    // 递归打印子节点
    printSubtreeReversed(node->firstChild, path, depth);

    // 递归打印兄弟节点，恢复深度
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

