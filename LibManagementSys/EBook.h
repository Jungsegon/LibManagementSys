#pragma once
#include "Book.h"

// Book 클래스를 상속받는 EBook 클래스
class EBook : public Book {
    string fileType; // ex) pdf -> 스트링으로 저장
    int numberOfPages; // 페이지 수는 정수형으로 저장
    //조건에서 제시된 멤버 변수들 선언
public:
    EBook(string t, string a, int y, string f, int n); //생성자
    void printInfo() const; //책정보를 출력하는 함수, 함수 오버라이딩
};