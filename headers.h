#pragma once
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)

// 域名树的节点
struct Node {
    char* name;           // 域名部分（如：www）
    Node* firstChild;     // 指向第一个子节点
    Node* nextSibling;    // 指向下一个兄弟节点
    int depth;            // 当前节点的深度

    // 构造函数，初始化节点
    Node(const char* name, int depth) : depth(depth) {
        this->name = strdup(name);  // 复制字符串
        this->firstChild = nullptr;
        this->nextSibling = nullptr;
    }

    // 析构函数，释放动态分配的内存
    ~Node() {
        delete[] name;  // 释放字符串内存
    }
};
