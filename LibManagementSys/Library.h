#include <vector>
#include <iostream>
#include "Book.h"

using namespace std;

//템플릿클래스 Library 선언.
template <typename T>
class Library { 
    // 멤버 변수 선언. 기본 private
    vector<T*> books; //벡터를 사용하며, T*로 동적할당하고, Book에서 파생되는 클래스타입임.
    //0부터 각각 동적으로 할당되며, 인덱스를 사용해서 삽입과 삭제가 용이함.
   
public:
    ~Library() { // 동적할당을 했으면 메모리를 해제해야 해서 소멸자사용
        // 동적할당된 모든 Book 객체 메모리를 해제.
        for (T* book : books) { //모든 객체 메모리
            delete book; // 해제 !
        }
    }

    // 도 서 추가하는 함수
    void addBook(T* book) {
        // 책을 동적할당 방식으로 추가.
        books.push_back(book);
    }

    void deleteBook(int index) { // 도서를 삭제하는 함수
        // 잘못된 인덱스 처리.
        if (index < 0 || index >= books.size()) { //인덱스는 0부터 이므로 0이하 이거나, 현재 입력된 수보다 높은 인덱스를 입력시
            cerr << "잘못된 인덱스입니다. 도서 삭제 실패 !!" << endl; // 실패 메시지 출력
            return;
        }
        // 동적할당된 객체 삭제 
        delete books[index]; 
        books.erase(books.begin() + index); // 벡터에서 제거.
    }

    // const로 변수의 내용을 변경하지 않음.
    // 저장된 모든 도서 정보를 출력하는 함수
    void printAllBooks() const {
        
        cout << endl; // 알아보기 쉽게 먼저 한줄을 띄우고,
        cout << "------------------------------저장된 책 정보----------------------------" << endl; // 제목 출력

        // 인덱스 0부터 저장된 모든 책 정보를 출력
        // 출력해서 사용자에게 보여줄 때는 0이 아니라 알아보기쉽게 인덱스를 +1해서 1부터시작하도록 보여줌.
        for (int i = 0; i < books.size(); ++i) {  
            cout << i + 1 << ". ";
            books[i]->printInfo(); // 해당 인덱스의 도서정보를 출력
        }
        cout << "------------------------------------------------------------------------" << endl;
        cout << endl; //다음 메뉴를 보기쉽게 한줄 또 띄우기.
    }
};