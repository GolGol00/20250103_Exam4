
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
public:
	Book(string title, string author);

	string GetTitle() const { return title; }
	string GetAuthor() const { return author; }

	~Book() {
	}
private:
	string title;
	string author;
};