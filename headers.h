#pragma once
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)

// �������Ľڵ�
struct Node {
    char* name;           // �������֣��磺www��
    Node* firstChild;     // ָ���һ���ӽڵ�
    Node* nextSibling;    // ָ����һ���ֵܽڵ�
    int depth;            // ��ǰ�ڵ�����

    // ���캯������ʼ���ڵ�
    Node(const char* name, int depth) : depth(depth) {
        this->name = strdup(name);  // �����ַ���
        this->firstChild = nullptr;
        this->nextSibling = nullptr;
    }

    // �����������ͷŶ�̬������ڴ�
    ~Node() {
        delete[] name;  // �ͷ��ַ����ڴ�
    }
};
