#include "headers.h"
#include "tools.h"
#include "insertTree.h"
#include "findTree.h"
#include "deleteDomain.h"

int main() {
    Node* root = new Node("", 0);  // 创建一个空的根节点

    while (true) {
        std::cout << "\n域名管理系统" << std::endl;
        std::cout << "1. 创建域名" << std::endl;
        std::cout << "2. 完整域名查询" << std::endl;
        std::cout << "3. 模糊域名查询并打印子树" << std::endl;
        std::cout << "4. 打印域名树（前序遍历）" << std::endl;
        std::cout << "5. 插入域名到特定层级" << std::endl;
        std::cout << "6. 删除域名" << std::endl;
        std::cout << "7. 退出" << std::endl;
        std::cout << "请输入操作选项 (1/2/3/4/5/6): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            // 创建域名
            std::cout << "请输入域名: ";
            char domain[100];
            std::cin >> domain;

            char* reversedDomain = reverseDomainParts(domain);
            createHelper(root, reversedDomain, 0);
            std::cout << "域名创建成功！" << std::endl;
        }
        else if (choice == 2) {
            // 完整域名查询
            std::cout << "请输入要查找的域名: ";
            char domain[100];
            std::cin >> domain;
            char* reversedDomain = reverseDomainParts(domain);

            Node* node = findExactNode(root, reversedDomain);
            if (node) {
                std::cout << "域名 " << domain << " 已找到。" << std::endl;
            }
            else {
                std::cout << "域名 " << domain << " 未找到。" << std::endl;
            }
        }
        else if (choice == 3) {
            // 模糊域名查询并打印子树
            std::cout << "请输入部分域名: ";
            char domain[100];
            std::cin >> domain;
            findVagueNode(root, domain);
        }
        else if (choice == 4) {
            // 打印域名树
            std::cout << "域名树结构（前序遍历）：" << std::endl;
            char path[500] = "";
            printSubtreeReversed(root, path, 0);
        }
        else if (choice == 5)
        {
            std::cout << "请输入层级: ";
            int targetDepth;
            std::cin >> targetDepth;
            std::cin.ignore();

            insertNode(root, targetDepth);
        }
        else if (choice == 6) {
            std::cout << "请输入删除域名: ";
            char deldomain[500];
            std::cin >> deldomain;
            deleteDomain(root, deldomain);
        }
        else if (choice == 7) {
            // 退出
            std::cout << "退出程序..." << std::endl;
            break;
        }
        
        else {
            std::cout << "无效的选项，请重新输入。" << std::endl;
        }

    }
}