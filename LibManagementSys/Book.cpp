#include "Book.h"
//Book 클래스
Book::Book(string t, string a, int y) {
    title = t;  // 제목초기화
    author = a; // 저자초기화
    publicationYear = y; // 출판연도초기화
}

Book::~Book() {} // Book 클래스 가상 소멸자