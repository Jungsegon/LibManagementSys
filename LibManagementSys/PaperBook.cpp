#include "PaperBook.h"

//Book 클래스의 생성자를 먼저 호출 한 다음, PaperBook 클래스의 추가 멤버변수 1개를 초기화
PaperBook::PaperBook(string t, string a, int y, int n) : Book(t, a, y) {
    numberOfPages = n; //페이지수 초기화
}

//const로 멤버 변수를 변경하지 않고, 책 정보를 출력
void PaperBook::printInfo() const {
    cout << "종이책 : " << title << " by " << author << " (" << publicationYear
        << ") " << numberOfPages << " pages." << endl;
}
