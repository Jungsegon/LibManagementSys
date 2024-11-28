#pragma once
#include <string>
#include <iostream>

using namespace std;

class Book {
protected: // 처음에 기본 타입private로 선언하였는데 다른 클래스에서 접근이 불가능하다는 것 잊어서 protected로 선언.
    string title;
    string author;
    int publicationYear;
    //조건에서 제시된 멤버 변수들 선언

public: //멤버 함수
    Book(string t, string a, int y); // 생성자
    virtual ~Book();  //가상 소멸자 
    virtual void printInfo() const = 0; //순수가상함수. 즉, 추상클래스로 정의함.
};