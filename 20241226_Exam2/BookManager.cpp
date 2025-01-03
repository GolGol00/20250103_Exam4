#include "BookManager.h"

BookManager::~BookManager()
{
	_books.clear();
	cout << "BookManager 소멸" << endl;
}

void BookManager::AddBook(Book addBook)
{
	_books.push_back(addBook);
	cout << "[제목]: " << addBook.GetTitle() << " [작가]: " << addBook.GetAuthor() << "책을 추가하였습니다." << endl;
}
//이동 시맨틱으로도 오버로딩해봤다.
void BookManager::AddBook(Book&& addBook) {
	_books.push_back(std::move(addBook));  // 이동 연산자 사용
	cout << "[제목]: " << addBook.GetTitle() << " [작가]: " << addBook.GetAuthor() << " 책을 추가하였습니다." << endl;
}

void BookManager::DisplayAllBooks()
{
	cout << "-----------------------------------------" << endl;
	cout << "보유하고있는 서적리스트" << endl;
	for (Book book : _books)
	{
		cout << "[제목]: " << book.GetTitle() << " [작가]: " << book.GetAuthor()  << endl;
	}
	cout << "-----------------------------------------" << endl;
}

void BookManager::SearchByTitle(string title)
{

	auto it = find_if(_books.begin(), _books.end(), [&](const Book& book) 
		{
		return book.GetTitle() == title;
		});

	if (it != _books.end()) {
		cout << "찾으시는 제목의 책이 있습니다: " << it->GetTitle() << " by " << it->GetAuthor() << endl;
	}
	else {
		cout << "찾으시는 제목의 책을 찾을 수 없습니다." << endl;
	}

}

void BookManager::SearchByAuthor(string author)
{
	auto it = find_if(_books.begin(), _books.end(), [&](const Book& book)
		{
			return book.GetAuthor() == author;
		});

	if (it != _books.end()) {
		cout << "찾으시는 작가의 책이 있습니다: " << it->GetTitle() << " by " << it->GetAuthor() << endl;
	}
	else {
		cout << "찾으시는 작가의 책을 찾을 수 없습니다." << endl;
	}
}
