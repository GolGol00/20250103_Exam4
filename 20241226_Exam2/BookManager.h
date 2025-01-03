#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

class BookManager
{

public:
	~BookManager();
	void AddBook(Book addBook);
	void AddBook(Book&& addBook);
	void DisplayAllBooks();
	void SearchByTitle(string title);
	void SearchByAuthor(string author);

	//º¯¼ö
private:
	vector<Book> _books;
};