#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "Book.h"
#include "BookManager.h"

using namespace std;

enum FUNCTION {
	ADD_BOOK = 1,
	FIND_TITLE,
	FIND_AUTHOR,
	DISPLAY_ALL_BOOK_INFO,
	SYSTEM_EXIT,
};

map<string, string> _libraryBookList;



void InitializeAddBook()
{
	_libraryBookList["소년이 온다"] = "한강";
	_libraryBookList["기생충"] = "봉준호";
	_libraryBookList["축구는 이렇게 하는거다"] = "손흥민";
	_libraryBookList["Prove it"] = "Faker";
	_libraryBookList["너 개발자가 되고싶어?"] = "Midam";
}
void PrintOpenLibraryMessage()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "도서관이 열렸습니다." << endl;
	cout << "이용하시곘습니까?" << endl;
	cout << "1: 이용하겠다. 2:다음에 올께" << endl;
	cout << "--------------------------------------------------------" << endl;
}
void PrintLibraryFunction() {
	cout << "---------------------------------------------" << endl;
	cout << "도서관을 이용합니다. 원하시는 기능을 입력하세요." << endl;
	cout << "1. 책 추가하기" << endl;
	cout << "2. 제목으로 검색하기" << endl;
	cout << "3. 작가 이름으로 검색하기" << endl;
	cout << "4. 도서관에 있는 모든 책 보기" << endl;
	cout << "5. 도서관 시스템 종료" << endl;
	cout << "---------------------------------------------" << endl;
}

void SetBookManager(BookManager& bookManager)
{
	cout << "도서관에 보유중인 초기책을 추가합니다." << endl;

	for (auto it : _libraryBookList) {
		Book newBook = Book(it.first, it.second);
		bookManager.AddBook(newBook);
	}
}

void OpenLibrary(BookManager& bookManager)
{

	int inputNum = 0;
	bool isRunning = true;
	string title = "";
	string author = "";
	while (isRunning == true) 
	{
		title = "";
		author = "";
		PrintLibraryFunction();
		cin >> inputNum;
		switch ((FUNCTION)inputNum)
		{
			case ADD_BOOK: {
				cout << "1. 책 추가하기(제목과 작가명을 입력하세요)" << endl;
				cin >> title >> author;
				Book newBook = Book(title, author);
				bookManager.AddBook(newBook);
				break;
			}
			case FIND_TITLE: {
				cout << "2. 제목으로 검색하기(제목을 입력하세요)" << endl;
				cin >> title;
				bookManager.SearchByTitle(title);
				break;
			}
			case FIND_AUTHOR: {
				cout << "3. 작가 이름으로 검색하기(작가명을 입력하세요)" << endl;
				cin >> author;
				bookManager.SearchByAuthor(author);
				break;
			}
			case DISPLAY_ALL_BOOK_INFO: {
				cout << "4. 도서관에 있는 모든 책 보기" << endl;
				bookManager.DisplayAllBooks();
				break;
			}
			case SYSTEM_EXIT: {
				cout << "도서관 시스템을 종료합니다." << endl;
				isRunning = false;
				break;
			}
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
		}
	}

	cout << "---------------------------------------------" << endl;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int main()
{

	BookManager* _bookManager = new BookManager();

	InitializeAddBook();
	PrintOpenLibraryMessage();
	SetBookManager(*_bookManager);
	OpenLibrary(*_bookManager);


	delete _bookManager;

	return 0;
}



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

