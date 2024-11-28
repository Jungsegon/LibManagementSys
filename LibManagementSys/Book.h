#pragma once
#include <string>
#include <iostream>

using namespace std;

class Book {
protected: // ó���� �⺻ Ÿ��private�� �����Ͽ��µ� �ٸ� Ŭ�������� ������ �Ұ����ϴٴ� �� �ؾ protected�� ����.
    string title;
    string author;
    int publicationYear;
    //���ǿ��� ���õ� ��� ������ ����

public: //��� �Լ�
    Book(string t, string a, int y); // ������
    virtual ~Book();  //���� �Ҹ��� 
    virtual void printInfo() const = 0; //���������Լ�. ��, �߻�Ŭ������ ������.
};