#include "BookManager.h"

BookManager::~BookManager()
{
	_books.clear();
	cout << "BookManager �Ҹ�" << endl;
}

void BookManager::AddBook(Book addBook)
{
	_books.push_back(addBook);
	cout << "[����]: " << addBook.GetTitle() << " [�۰�]: " << addBook.GetAuthor() << "å�� �߰��Ͽ����ϴ�." << endl;
}
//�̵� �ø�ƽ���ε� �����ε��غô�.
void BookManager::AddBook(Book&& addBook) {
	_books.push_back(std::move(addBook));  // �̵� ������ ���
	cout << "[����]: " << addBook.GetTitle() << " [�۰�]: " << addBook.GetAuthor() << " å�� �߰��Ͽ����ϴ�." << endl;
}

void BookManager::DisplayAllBooks()
{
	cout << "-----------------------------------------" << endl;
	cout << "�����ϰ��ִ� ��������Ʈ" << endl;
	for (Book book : _books)
	{
		cout << "[����]: " << book.GetTitle() << " [�۰�]: " << book.GetAuthor()  << endl;
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
		cout << "ã���ô� ������ å�� �ֽ��ϴ�: " << it->GetTitle() << " by " << it->GetAuthor() << endl;
	}
	else {
		cout << "ã���ô� ������ å�� ã�� �� �����ϴ�." << endl;
	}

}

void BookManager::SearchByAuthor(string author)
{
	auto it = find_if(_books.begin(), _books.end(), [&](const Book& book)
		{
			return book.GetAuthor() == author;
		});

	if (it != _books.end()) {
		cout << "ã���ô� �۰��� å�� �ֽ��ϴ�: " << it->GetTitle() << " by " << it->GetAuthor() << endl;
	}
	else {
		cout << "ã���ô� �۰��� å�� ã�� �� �����ϴ�." << endl;
	}
}
