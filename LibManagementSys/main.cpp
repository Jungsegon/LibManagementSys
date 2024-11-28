#include "EBook.h"
#include "PaperBook.h"
#include "Library.h"

// do while���� �ڵ� �������� ���� �޴� �Լ� ����
void displayMenu() {
    cout << "\n======= ���� ���� �ý��� =======\n"
         << "1. ���� �߰��ϱ�\n"
         << "2. ���� �����ϱ�\n"
         << "3. ��� ���� ��� ��ȸ\n"
         << "4. ������\n"
         << "1~4 �� �� ���� : ";
}

int main() {
    Library<Book> library;  
    //Book���� �Ļ��Ǵ� ���ø� Ŭ����, Library

    // ������ ���� �̸� ���� 4���� �����س���
    library.addBook(new EBook("Digital Fortress", "Dan Brown", 1998, "PDF", 546));
    library.addBook(new EBook("Clean Code", "Robert C. Martin", 2008, "EPUB", 754));
    library.addBook(new PaperBook("1984", "George Orwell", 1949, 328));
    library.addBook(new PaperBook("To Kill a Mockingbird", "Harper Lee", 1960, 281));

    int choice; // ��ȣ ������ ���� ����

    do { // �Լ��� ������ ���� ���� �� ���ǿ� ���� �ݺ�
        displayMenu(); //�޴� �Լ��� �ҷ���
        cin >> choice; // 1~4���� �����ϱ� ���� ���� �Է�

        switch (choice) { // ������� ���ÿ� ���� ����
        case 1: { // ���� �߰��ϱ�
            int type; // ���� ���� �Է��� ���� ���� (1��, 2��)
            cout << "���� ������ �Է��ϼ��� (1: ����å, 2: ����å): ";
            cin >> type; // ����ڷκ��� ���� ���� �Է�
            cin.ignore(); // �Է� ���۸� �����

            string title, author, fileType; // ���� ������ ������ ����
            int year, pages; // ���ǳ⵵�� ������ ��

            cout << "���� ������ �Է��ϼ���: "; // ���� ���� �Է�
            getline(cin, title); // ���� �Է�
            cout << "���ڸ� �Է��ϼ���: "; // ���� �Է�
            getline(cin, author); // ���� �Է�
            cout << "���� ������ �Է��ϼ���: "; // ���ǿ��� �Է�
            cin >> year; // ���� �Է�

            if (type == 1) { // ����å�� ���
                cout << "���� ������ �Է��ϼ���: "; // ���� ���� �Է�
                cin >> fileType; // ���� ���� �Է� ex) pdf
                cout << "������ ���� �Է��ϼ���: "; // ������ �� �Է�
                cin >> pages; // ������ �� �Է�
                library.addBook(new EBook(title, author, year, fileType, pages)); // ����å �߰�
            }
            else if (type == 2) { // ����å�� ���
                cout << "������ ���� �Է��ϼ���: "; // ������ �� �Է�
                cin >> pages; // ������ �� �Է�
                library.addBook(new PaperBook(title, author, year, pages)); // ����å �߰�
            }
            else { // �ٸ� ���� �Է��� ���
                cerr << "�߸��� ���� �����Դϴ�." << endl;
            }
            break; // case1 ���� �� ���ư�
        }
        case 2: { // ���� �����ϱ�
            int index; // ������ ������ �ε����� �Է¹��� ����
            cout << "������ ������ �ε����� �Է��ϼ���: "; // �ε��� �Է�
            cin >> index; // ����ڷκ��� �ε��� �Է�
            library.deleteBook(index - 1); // �ش� �ε����� ���� ���� �ε����� 0���� �����ϹǷ� -1�� ���ش�.
            break; // case2 ���� �� ���ư�
        }
        case 3: // ��� ���� ��� ��ȸ
            library.printAllBooks(); // ����� ��� ���� ���
            break;
        case 4: // ���α׷� ����
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        default: // �߸��� ������ �Է��� ���
            cerr << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    } while (choice != 4); // 4��(����) ���� �� ���� ���� �� ���α׷� ����

    return 0; // ���α׷� ���� ����
}