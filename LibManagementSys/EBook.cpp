#include "EBook.h"

// Book클래스의 생성자를 호출한 다음, EBook클래스에서 2 추가 멤벼변수 2개 초기화
EBook::EBook(string t, string a, int y, string f, int n) : Book(t, a, y) {
    fileType = f; // 파일 타입초기화
    numberOfPages = n; // 페이지수 초기화
}

void EBook::printInfo() const { // 책정보를 출력, const는 멤버변수를 수정하지 않는 것을 의미.
    // title, author와 같은 멤버 변수의 값을 변경하려고 하면 컴파일 오류 발생
    // 멤버 변수들을 출력
    cout << "E-Book: " << title << " by " << author << " (" << publicationYear
        << ") [" << fileType << "] " << numberOfPages << " pages." << endl;
}