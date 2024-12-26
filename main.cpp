#include "headers.h"
#include "tools.h"
#include "insertTree.h"
#include "findTree.h"
#include "categoryfind.h"
#include "deleteDomain.h"
#include "userdomainGet.h"

int main() {
    Node* root = new Node("", 0);  // ����һ���յĸ��ڵ�

    while (true) {
        std::cout << "\n��������ϵͳ" << std::endl;
        std::cout << "1. ��������" << std::endl;
        std::cout << "2. ����������ѯ" << std::endl;
        std::cout << "3. ģ��������ѯ����ӡ����" << std::endl;
        std::cout << "4. ��ӡ��������ǰ�������" << std::endl;
        std::cout << "5. �����������ض��㼶" << std::endl;
        std::cout << "6. ɾ������" << std::endl;
        std::cout << "7. �����ѯ" << std::endl;
        std::cout << "8. ��ѯ�û���������" << std::endl;
        std::cout << "9. �˳�" << std::endl;
        std::cout << "���������ѡ�� (1/2/3/4/5/6): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            // ��������
            std::cout << "����������: ";
            char domain[100];
            std::cin >> domain;

            char* reversedDomain = reverseDomainParts(domain);
            createHelper(root, reversedDomain, 0);
            std::cout << "���������ɹ���" << std::endl;
        }
        else if (choice == 2) {
            // ����������ѯ
            std::cout << "������Ҫ���ҵ�����: ";
            char domain[100];
            std::cin >> domain;
            char* reversedDomain = reverseDomainParts(domain);

            Node* node = findExactNode(root, reversedDomain);
            if (node) {
                std::cout << "���� " << domain << " ���ҵ���"<< std::endl;
            }
            else {
                std::cout << "���� " << domain << " δ�ҵ���" << std::endl;
            }
        }
        else if (choice == 3) {
            // ģ��������ѯ����ӡ����
            std::cout << "�����벿������: ";
            char domain[100];
            std::cin >> domain;
            findVagueNode(root, domain);
        }
        else if (choice == 4) {
            // ��ӡ������
            std::cout << "�������ṹ��ǰ���������" << std::endl;
            char path[500] = "";
            printSubtreeReversed(root, path, 0);
        }
        else if (choice == 5)
        {
            std::cout << "������㼶: ";
            int targetDepth;
            std::cin >> targetDepth;
            std::cin.ignore();

            insertNode(root, targetDepth);
        }
        else if (choice == 6) {
            std::cout << "������ɾ������: ";
            char deldomain[500];
            std::cin >> deldomain;
            deleteDomain(root, deldomain);
        }
        else if (choice == 7) {
            int temchoice;
            std::cout << "����������ѡ��Ҫ��ѯ�����" << std::endl;
            std::cout << "1. ��ҵ��" << std::endl;
            std::cout << "2. ��֯��" << std::endl;
            std::cout << "3. ������" << std::endl;
            std::cout << "4. ������" << std::endl;
            std::cout << "5. ������" << std::endl;
            std::cout << "6. �Ƽ���" << std::endl;
            std::cout << "7. ���ۺ��̵���" << std::endl;
            std::cout << "8. ������" << std::endl;
            std::cout << "9. ������" << std::endl;
            std::cout << "10. ������" << std::endl;
            std::cout << "11. Ӧ�ó�����" << std::endl;
            std::cout << "12. ��������" << std::endl;
            std::cout << "13. ������" << std::endl;
            std::cout << "14. ������" << std::endl;
            std::cout << "15. �������" << std::endl;
            std::cout << "������ѡ��";
            std::cin >> temchoice;
            if (temchoice - 1 >= 0 && temchoice - 1 < 15)
            {
                std::cout << "��ѯ������µĶ�������Ϊ��" << std::endl;
                categoryfind(root, temchoice);
                std::cout << "������ѡ���Ƿ�Ҫ��ӡ�����ĵ�ĳ��������1���ǣ�0���񣩣�";
                int otherchoice;
                std::cin >> otherchoice;
                if (otherchoice == 1)
                {
                    char domain[100];
                    std::cout << "��������Ҫ��ӡ�������Ķ���������" << std::endl;
                    std::cin >> domain;
                    char* reversedDomain = reverseDomainParts(domain);
                    Node* node = findExactNode(root, reversedDomain);
                    printFullDomainPath(node);
                }
            }
        }else if (choice == 8) {
            char path[256] = "";
            char validPaths[MAX_PATHS][MAX_PATH_LEN];  // �洢·��
            int validPathCount = 0;
            char user[128]="";
            std::cout << "�������û�" << std::endl;
            std::cin >> user;
            std::cin.ignore();
            char* reverseDomainParts(const char* path);
            printSubtreeUser(root, path, 0, user, validPaths, validPathCount);
            printValidPaths(validPaths, validPathCount);  // ��ӡ��������������·��
        }
        else if (choice == 9) {
            // �˳�
            std::cout << "�˳�����..." << std::endl;
            break;
        }
        
        else {
            std::cout << "��Ч��ѡ����������롣" << std::endl;
        }

    }
}