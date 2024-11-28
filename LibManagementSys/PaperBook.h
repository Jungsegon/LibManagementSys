#include "Book.h"

//Book클래스를 상속받는 PaperBook 클래스
class PaperBook : public Book {
    int numberOfPages;//PaperBook의 추가 멤버변수

public: // 멤버함수
    PaperBook(string t, string a, int y, int n); // 생성자, 추가 멤버변수도 포함 
    void printInfo() const; //책 정보를 출력하는 함수, 함수 오버라이딩
};
