#include "EBook.h"

// BookŬ������ �����ڸ� ȣ���� ����, EBookŬ�������� 2 �߰� �⺭���� 2�� �ʱ�ȭ
EBook::EBook(string t, string a, int y, string f, int n) : Book(t, a, y) {
    fileType = f; // ���� Ÿ���ʱ�ȭ
    numberOfPages = n; // �������� �ʱ�ȭ
}

void EBook::printInfo() const { // å������ ���, const�� ��������� �������� �ʴ� ���� �ǹ�.
    // title, author�� ���� ��� ������ ���� �����Ϸ��� �ϸ� ������ ���� �߻�
    // ��� �������� ���
    cout << "E-Book: " << title << " by " << author << " (" << publicationYear
        << ") [" << fileType << "] " << numberOfPages << " pages." << endl;
}