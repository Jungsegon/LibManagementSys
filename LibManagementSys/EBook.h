#pragma once
#include "Book.h"

// Book Ŭ������ ��ӹ޴� EBook Ŭ����
class EBook : public Book {
    string fileType; // ex) pdf -> ��Ʈ������ ����
    int numberOfPages; // ������ ���� ���������� ����
    //���ǿ��� ���õ� ��� ������ ����
public:
    EBook(string t, string a, int y, string f, int n); //������
    void printInfo() const; //å������ ����ϴ� �Լ�, �Լ� �������̵�
};