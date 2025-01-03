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
	_libraryBookList["�ҳ��� �´�"] = "�Ѱ�";
	_libraryBookList["�����"] = "����ȣ";
	_libraryBookList["�౸�� �̷��� �ϴ°Ŵ�"] = "�����";
	_libraryBookList["Prove it"] = "Faker";
	_libraryBookList["�� �����ڰ� �ǰ�;�?"] = "Midam";
}
void PrintOpenLibraryMessage()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "�������� ���Ƚ��ϴ�." << endl;
	cout << "�̿��ϽÁٽ��ϱ�?" << endl;
	cout << "1: �̿��ϰڴ�. 2:������ �ò�" << endl;
	cout << "--------------------------------------------------------" << endl;
}
void PrintLibraryFunction() {
	cout << "---------------------------------------------" << endl;
	cout << "�������� �̿��մϴ�. ���Ͻô� ����� �Է��ϼ���." << endl;
	cout << "1. å �߰��ϱ�" << endl;
	cout << "2. �������� �˻��ϱ�" << endl;
	cout << "3. �۰� �̸����� �˻��ϱ�" << endl;
	cout << "4. �������� �ִ� ��� å ����" << endl;
	cout << "5. ������ �ý��� ����" << endl;
	cout << "---------------------------------------------" << endl;
}

void SetBookManager(BookManager& bookManager)
{
	cout << "�������� �������� �ʱ�å�� �߰��մϴ�." << endl;

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
				cout << "1. å �߰��ϱ�(����� �۰����� �Է��ϼ���)" << endl;
				cin >> title >> author;
				Book newBook = Book(title, author);
				bookManager.AddBook(newBook);
				break;
			}
			case FIND_TITLE: {
				cout << "2. �������� �˻��ϱ�(������ �Է��ϼ���)" << endl;
				cin >> title;
				bookManager.SearchByTitle(title);
				break;
			}
			case FIND_AUTHOR: {
				cout << "3. �۰� �̸����� �˻��ϱ�(�۰����� �Է��ϼ���)" << endl;
				cin >> author;
				bookManager.SearchByAuthor(author);
				break;
			}
			case DISPLAY_ALL_BOOK_INFO: {
				cout << "4. �������� �ִ� ��� å ����" << endl;
				bookManager.DisplayAllBooks();
				break;
			}
			case SYSTEM_EXIT: {
				cout << "������ �ý����� �����մϴ�." << endl;
				isRunning = false;
				break;
			}
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
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

