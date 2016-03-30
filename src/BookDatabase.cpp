/*
 * BookDatabase.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: quan
 */

#include <BookDatabase.h>

using namespace std;
using namespace utility;

namespace LibraryCatalog {

BookDatabase::BookDatabase() 
{
	mNoBook.setISBN("0000000000");
}

BookDatabase::~BookDatabase() 
{
	/* Empty on purpose */
}

Book& BookDatabase::addBook(const string bookName, const string ISBN,
					  const string authorFirstName, const string authorLastName,
					  const string publisher, int yearOfPublication,
					  Subject subject)
{
	// Check for existing ISBN
	if (mBooks.find(ISBN) != mBooks.end())
		throw runtime_error("ISBN already existed in the database!");
	
	// Check for empty book name
	if (bookName.length() == 0)
		throw runtime_error("Book's name must not be empty!");

	// Add the book the database
	Book newBook = Book(bookName, ISBN, authorFirstName, authorLastName,
			publisher, yearOfPublication, subject);
	mBooks[ISBN] = newBook;

	return mBooks[ISBN];
}


Book& BookDatabase::addBook(Book book)
{
	string bookISBN = book.getISBN();
	string bookName = book.getBookName();

	// Check for existing ISBN
	if (mBooks.find(bookISBN) != mBooks.end())
		throw runtime_error("ISBN already existed in the database!");
	
	// Check for empty book name
	if (bookName.length() == 0)
		throw runtime_error("Book's name must not be empty!");

	// Add the book to the database
	mBooks[bookISBN] = book;

	return mBooks[bookISBN];
}


vector<Book> BookDatabase::searchBookByName(string bookName)
{
	vector<Book> results;
	bookName = lower(bookName);

	for (auto const& book : mBooks) {
		string currentBookName = book.second.getBookName();
		currentBookName = lower(currentBookName);

		if (currentBookName.find(bookName) != string::npos)
			results.push_back(book.second);
	}

	return results;
}


vector<Book> BookDatabase::searchBookByAuthor(string authorFirstName,
                                                   string authorLastName)
{
	vector<Book> results;
	string firstName = lower(authorFirstName);
	string lastName = lower(authorLastName);

	for (auto const& book : mBooks) {
		string bookAuthorFirstName = lower(book.second.getAuthorFirstName());
		string bookAuthorLastName = lower(book.second.getAuthorLastName());

		if (bookAuthorFirstName.find(firstName) != string::npos)
			results.push_back(book.second);
		if (bookAuthorLastName.find(lastName) != string::npos)
			results.push_back(book.second);
	}

	return results;
}


vector<Book> BookDatabase::searchBookByPublisher(string publisher)
{
	vector<Book> results;
	publisher = lower(publisher);

	for (auto const& book : mBooks) {
		string currentPublisher = book.second.getPublisher();
		currentPublisher = lower(currentPublisher);

		if (currentPublisher.find(publisher) != string::npos)
			results.push_back(book.second);
	}

	return results;
}


Book& BookDatabase::getBookByISBN(const string ISBN)
{
	if (mBooks.find(ISBN) != mBooks.end())
		return mBooks[ISBN];
	else
		throw runtime_error("Book doesn't exist!");
}

} /* namespace LibraryCatalog */
