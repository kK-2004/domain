#include"categoryfind.h"

void categoryfind(Node* node, int temchoice)
{
    // ��鵱ǰ�ڵ��Ƿ���Ч
    if (node == nullptr) return;
    // ������ǰ�ڵ�������ӽڵ�
    // ���÷��࣬Ĭ��ֵ�� other
    category Category = other;
    Category = static_cast<category>(temchoice - 1);
    if (node->depth == 2)
    {
        if (node->nodeCategory == Category) {
            std::cout << node->name << std::endl;
        }
    }
    // �ݹ�����ӽڵ�
    categoryfind(node->firstChild, temchoice); // �ݹ鵽�ӽڵ�
    // �����ֵܽڵ�
    categoryfind(node->nextSibling, temchoice);
}

