#include "PaperBook.h"

//Book Ŭ������ �����ڸ� ���� ȣ�� �� ����, PaperBook Ŭ������ �߰� ������� 1���� �ʱ�ȭ
PaperBook::PaperBook(string t, string a, int y, int n) : Book(t, a, y) {
    numberOfPages = n; //�������� �ʱ�ȭ
}

//const�� ��� ������ �������� �ʰ�, å ������ ���
void PaperBook::printInfo() const {
    cout << "����å : " << title << " by " << author << " (" << publicationYear
        << ") " << numberOfPages << " pages." << endl;
}
