#include "createTree.h"

// 使用 const char* 数组映射每个枚举值到对应的字符串
const char* categoryToString(category cat)
{
    switch (cat) {
    case commerce: return "commerce";
    case organization: return "organization";
    case network: return "network";
    case education: return "education";
    case goverment: return "goverment";
    case technology: return "technology";
    case store: return "store";
    case blog: return "blog";
    case law: return "law";
    case health: return "health";
    case app: return "app";
    case dev: return "dev";
    case news: return "news";
    case music: return "music";
    case other: return "other";
    default: return "unknow"; // 防止无效值
    }
}

void createHelper(Node* node, const char* domain, int depth)
{
    // 检查 node 是否为空
    if (!node) {
        std::cerr << "Error: Node is null!" << std::endl;
        return;
    }

    const char* remainingDomain = strchr(domain, '.');
    size_t partLength = (remainingDomain == nullptr) ? strlen(domain) : remainingDomain - domain;

    // 分配内存，确保 '\0' 结尾
    char* part = new char[partLength + 1];
    strncpy(part, domain, partLength);
    part[partLength] = '\0';

    // 查找子节点，查看是否已存在
    Node* child = node->firstChild;
    while (child) {
        if (strcmp(child->name, part) == 0) {
            delete[] part;  // 释放临时内存
            if (remainingDomain == nullptr) return;
            createHelper(child, remainingDomain + 1, depth + 1);
            return;
        }
        child = child->nextSibling;
    }

    // 创建新节点
    Node* newNode = new Node(part, depth + 1, node);  // 假设 Node 构造函数正确处理 name
    delete[] part; // 释放 part
    if (depth >= 1) {
        std::cout << "请输入用户ID: ";
        char temid[100];
        std::cin >> temid;

        // 为 ID 分配内存并拷贝字符串
        newNode->id = new char[strlen(temid) + 1];
        strcpy(newNode->id, temid);
    }
    if (depth == 1) {

        // 选择类别
        std::cout << "请输入数字选择二级域名的类别：" << std::endl;
        std::cout << "1. 商业类\n2. 组织类\n3. 网络类\n4. 教育类\n5. 政府类\n6. 科技类\n7. 零售和商店类\n"
            "8. 博客类\n9. 法律类\n10. 健康类\n11. 应用程序类\n12. 开发者类\n13. 新闻类\n14. 音乐类\n15. 其它类别" << std::endl;
        int temchoice;
        std::cout << "请输入选择：";
        std::cin >> temchoice;

        category Category = other;  // 默认分类
        if (temchoice >= 1 && temchoice <= 15) {
            Category = static_cast<category>(temchoice - 1);
            newNode->nodeCategory = Category;
        }
        else {
            std::cerr << "Invalid category choice!" << std::endl;
        }
        std::cout << categoryToString(newNode->nodeCategory) << "类" << std::endl;
    }

    // 将新节点加入到父节点的子节点链表中
    newNode->nextSibling = node->firstChild;
    node->firstChild = newNode;

    // 递归处理剩余的域名部分
    if (remainingDomain != nullptr) {
        createHelper(newNode, remainingDomain + 1, depth + 1);
    }
}

