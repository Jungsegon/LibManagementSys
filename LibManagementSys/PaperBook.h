#include "Book.h"

//BookŬ������ ��ӹ޴� PaperBook Ŭ����
class PaperBook : public Book {
    int numberOfPages;//PaperBook�� �߰� �������

public: // ����Լ�
    PaperBook(string t, string a, int y, int n); // ������, �߰� ��������� ���� 
    void printInfo() const; //å ������ ����ϴ� �Լ�, �Լ� �������̵�
};
