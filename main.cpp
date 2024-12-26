#include "headers.h"
#include "tools.h"
#include "insertTree.h"
#include "findTree.h"
#include "categoryfind.h"
#include "deleteDomain.h"
#include "userdomainGet.h"

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
        std::cout << "7. 分类查询" << std::endl;
        std::cout << "8. 查询用户所有域名" << std::endl;
        std::cout << "9. 退出" << std::endl;
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
                std::cout << "域名 " << domain << " 已找到。"<< std::endl;
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
            int temchoice;
            std::cout << "请输入数字选择要查询的类别：" << std::endl;
            std::cout << "1. 商业类" << std::endl;
            std::cout << "2. 组织类" << std::endl;
            std::cout << "3. 网络类" << std::endl;
            std::cout << "4. 教育类" << std::endl;
            std::cout << "5. 政府类" << std::endl;
            std::cout << "6. 科技类" << std::endl;
            std::cout << "7. 零售和商店类" << std::endl;
            std::cout << "8. 博客类" << std::endl;
            std::cout << "9. 法律类" << std::endl;
            std::cout << "10. 健康类" << std::endl;
            std::cout << "11. 应用程序类" << std::endl;
            std::cout << "12. 开发者类" << std::endl;
            std::cout << "13. 新闻类" << std::endl;
            std::cout << "14. 音乐类" << std::endl;
            std::cout << "15. 其它类别" << std::endl;
            std::cout << "请输入选择：";
            std::cin >> temchoice;
            if (temchoice - 1 >= 0 && temchoice - 1 < 15)
            {
                std::cout << "查询的类别下的二级域名为：" << std::endl;
                categoryfind(root, temchoice);
                std::cout << "请输入选择是否要打印该类别的的某个域名（1：是，0：否）：";
                int otherchoice;
                std::cin >> otherchoice;
                if (otherchoice == 1)
                {
                    char domain[100];
                    std::cout << "请输入想要打印的域名的二级域名：" << std::endl;
                    std::cin >> domain;
                    char* reversedDomain = reverseDomainParts(domain);
                    Node* node = findExactNode(root, reversedDomain);
                    printFullDomainPath(node);
                }
            }
        }else if (choice == 8) {
            char path[256] = "";
            char validPaths[MAX_PATHS][MAX_PATH_LEN];  // 存储路径
            int validPathCount = 0;
            char user[128]="";
            std::cout << "请输入用户" << std::endl;
            std::cin >> user;
            std::cin.ignore();
            char* reverseDomainParts(const char* path);
            printSubtreeUser(root, path, 0, user, validPaths, validPathCount);
            printValidPaths(validPaths, validPathCount);  // 打印所有满足条件的路径
        }
        else if (choice == 9) {
            // 退出
            std::cout << "退出程序..." << std::endl;
            break;
        }
        
        else {
            std::cout << "无效的选项，请重新输入。" << std::endl;
        }

    }
}