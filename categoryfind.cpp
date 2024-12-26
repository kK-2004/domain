#include"categoryfind.h"

void categoryfind(Node* node, int temchoice)
{
    // 检查当前节点是否有效
    if (node == nullptr) return;
    // 遍历当前节点的所有子节点
    // 设置分类，默认值是 other
    category Category = other;
    Category = static_cast<category>(temchoice - 1);
    if (node->depth == 2)
    {
        if (node->nodeCategory == Category) {
            std::cout << node->name << std::endl;
        }
    }
    // 递归遍历子节点
    categoryfind(node->firstChild, temchoice); // 递归到子节点
    // 遍历兄弟节点
    categoryfind(node->nextSibling, temchoice);
}

