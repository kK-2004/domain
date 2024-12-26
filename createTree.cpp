#include "createTree.h"

// ʹ�� const char* ����ӳ��ÿ��ö��ֵ����Ӧ���ַ���
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
    default: return "unknow"; // ��ֹ��Чֵ
    }
}

void createHelper(Node* node, const char* domain, int depth)
{
    // ��� node �Ƿ�Ϊ��
    if (!node) {
        std::cerr << "Error: Node is null!" << std::endl;
        return;
    }

    const char* remainingDomain = strchr(domain, '.');
    size_t partLength = (remainingDomain == nullptr) ? strlen(domain) : remainingDomain - domain;

    // �����ڴ棬ȷ�� '\0' ��β
    char* part = new char[partLength + 1];
    strncpy(part, domain, partLength);
    part[partLength] = '\0';

    // �����ӽڵ㣬�鿴�Ƿ��Ѵ���
    Node* child = node->firstChild;
    while (child) {
        if (strcmp(child->name, part) == 0) {
            delete[] part;  // �ͷ���ʱ�ڴ�
            if (remainingDomain == nullptr) return;
            createHelper(child, remainingDomain + 1, depth + 1);
            return;
        }
        child = child->nextSibling;
    }

    // �����½ڵ�
    Node* newNode = new Node(part, depth + 1, node);  // ���� Node ���캯����ȷ���� name
    delete[] part; // �ͷ� part
    if (depth >= 1) {
        std::cout << "�������û�ID: ";
        char temid[100];
        std::cin >> temid;

        // Ϊ ID �����ڴ沢�����ַ���
        newNode->id = new char[strlen(temid) + 1];
        strcpy(newNode->id, temid);
    }
    if (depth == 1) {

        // ѡ�����
        std::cout << "����������ѡ��������������" << std::endl;
        std::cout << "1. ��ҵ��\n2. ��֯��\n3. ������\n4. ������\n5. ������\n6. �Ƽ���\n7. ���ۺ��̵���\n"
            "8. ������\n9. ������\n10. ������\n11. Ӧ�ó�����\n12. ��������\n13. ������\n14. ������\n15. �������" << std::endl;
        int temchoice;
        std::cout << "������ѡ��";
        std::cin >> temchoice;

        category Category = other;  // Ĭ�Ϸ���
        if (temchoice >= 1 && temchoice <= 15) {
            Category = static_cast<category>(temchoice - 1);
            newNode->nodeCategory = Category;
        }
        else {
            std::cerr << "Invalid category choice!" << std::endl;
        }
        std::cout << categoryToString(newNode->nodeCategory) << "��" << std::endl;
    }

    // ���½ڵ���뵽���ڵ���ӽڵ�������
    newNode->nextSibling = node->firstChild;
    node->firstChild = newNode;

    // �ݹ鴦��ʣ�����������
    if (remainingDomain != nullptr) {
        createHelper(newNode, remainingDomain + 1, depth + 1);
    }
}

