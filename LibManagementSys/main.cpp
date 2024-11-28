#include "EBook.h"
#include "PaperBook.h"
#include "Library.h"

// do while문에 코드 가독성을 위한 메뉴 함수 구현
void displayMenu() {
    cout << "\n======= 도서 관리 시스템 =======\n"
         << "1. 도서 추가하기\n"
         << "2. 도서 삭제하기\n"
         << "3. 모든 도서 목록 조회\n"
         << "4. 나가기\n"
         << "1~4 번 중 선택 : ";
}

int main() {
    Library<Book> library;  
    //Book에서 파생되는 템플릿 클래스, Library

    // 예제에 따라 미리 도서 4개를 정의해놓음
    library.addBook(new EBook("Digital Fortress", "Dan Brown", 1998, "PDF", 546));
    library.addBook(new EBook("Clean Code", "Robert C. Martin", 2008, "EPUB", 754));
    library.addBook(new PaperBook("1984", "George Orwell", 1949, 328));
    library.addBook(new PaperBook("To Kill a Mockingbird", "Harper Lee", 1960, 281));

    int choice; // 번호 선택을 위한 변수

    do { // 함수의 내용을 먼저 실행 후 조건에 따라 반복
        displayMenu(); //메뉴 함수를 불러옴
        cin >> choice; // 1~4번을 선택하기 위한 정수 입력

        switch (choice) { // 사용자의 선택에 따라 실행
        case 1: { // 도서 추가하기
            int type; // 도서 종류 입력을 위한 변수 (1번, 2번)
            cout << "도서 유형을 입력하세요 (1: 전자책, 2: 종이책): ";
            cin >> type; // 사용자로부터 도서 유형 입력
            cin.ignore(); // 입력 버퍼를 비워줌

            string title, author, fileType; // 도서 정보를 저장할 변수
            int year, pages; // 출판년도와 페이지 수

            cout << "도서 제목을 입력하세요: "; // 도서 제목 입력
            getline(cin, title); // 제목 입력
            cout << "저자를 입력하세요: "; // 저자 입력
            getline(cin, author); // 저자 입력
            cout << "출판 연도를 입력하세요: "; // 출판연도 입력
            cin >> year; // 연도 입력

            if (type == 1) { // 전자책인 경우
                cout << "파일 형식을 입력하세요: "; // 파일 형식 입력
                cin >> fileType; // 파일 형식 입력 ex) pdf
                cout << "페이지 수를 입력하세요: "; // 페이지 수 입력
                cin >> pages; // 페이지 수 입력
                library.addBook(new EBook(title, author, year, fileType, pages)); // 전자책 추가
            }
            else if (type == 2) { // 종이책인 경우
                cout << "페이지 수를 입력하세요: "; // 페이지 수 입력
                cin >> pages; // 페이지 수 입력
                library.addBook(new PaperBook(title, author, year, pages)); // 종이책 추가
            }
            else { // 다른 내용 입력한 경우
                cerr << "잘못된 도서 유형입니다." << endl;
            }
            break; // case1 종료 후 돌아감
        }
        case 2: { // 도서 삭제하기
            int index; // 삭제할 도서의 인덱스를 입력받을 변수
            cout << "삭제할 도서의 인덱스를 입력하세요: "; // 인덱스 입력
            cin >> index; // 사용자로부터 인덱스 입력
            library.deleteBook(index - 1); // 해당 인덱스의 도서 삭제 인덱스는 0에서 시작하므로 -1을 해준다.
            break; // case2 종료 후 돌아감
        }
        case 3: // 모든 도서 목록 조회
            library.printAllBooks(); // 저장된 모든 도서 출력
            break;
        case 4: // 프로그램 종료
            cout << "프로그램을 종료합니다." << endl;
            break;
        default: // 잘못된 변수를 입력할 경우
            cerr << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    } while (choice != 4); // 4번(종료) 선택 시 루프 종료 후 프로그램 종료

    return 0; // 프로그램 정상 종료
}