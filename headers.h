#pragma once
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)


#define MAX_PATHS 100  // ���·������
#define MAX_PATH_LEN 256  // ����·����󳤶�

enum category
{
    commerce = 0, organization, network, education, goverment, technology,
    store, blog, law, health, app, dev, news, music, other
};



// �������Ľڵ�
struct Node {
    char* name;           // �������֣��磺www��
    Node* firstChild;     // ָ���һ���ӽڵ�
    Node* nextSibling;    // ָ����һ���ֵܽڵ�
    Node* parent;         // ָ�򸸽ڵ�
    int depth;            // ��ǰ�ڵ�����
    char *id;
    enum category nodeCategory;
    // ���캯������ʼ���ڵ�
    Node(const char* name, int depth, Node* parent = nullptr)
        : depth(depth), parent(parent) {
        this->name = strdup(name);  // �����ַ���
        this->firstChild = nullptr;
        this->nextSibling = nullptr;
        this->id = strdup("");
    }
    // �����������ͷŶ�̬������ڴ�
    ~Node() {
        delete[] name;  // �ͷ��ַ����ڴ�
    }
};
