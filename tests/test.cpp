//============================================================================
// Name        : Library.cpp
// Author      : Quan Tran
// Version     :
// Copyright   : Copyright held by the author
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <format.h>
#include <Book.h>
#include <BookDatabase.h>
#include <Patron.h>
#include <PatronDatabase.h>
#include <Constants.h>
#include <LibraryCatalogApp.h>

using namespace std;
using namespace LibraryCatalog;

int main()
{
	/*// Create books
	Book myBook;
	myBook.setAuthorFirstName("Quan");
	myBook.setAuthorLastName("Tran");
	myBook.setBookName("C++ Programming");
	myBook.setISBN("1234567890");
	myBook.setPublisher("Quan Tran Publisher");
	myBook.setSubject(Subject::NaturalScience);
	myBook.setYearOfPublication(2015);

	Book anotherBook = Book("The Pragmatic Programmer", "1101010011", "Linus",
			"Torvalds", "Denison University", 1999, Subject::NaturalScience);

	// Create a patron
	Patron myPatron;
	myPatron.setPatronID("D01711540");
	myPatron.setPatronName("Quan M. Tran");

	// Add a patron to database
	PatronDatabase patronDB;
	patronDB.addPatron(myPatron);
	myPatron.setPatronID("D01111111");

	try {
		Patron patronFound = patronDB.getPatronByID("D01711540");
		fmt::print(patronFound.display());
	} catch (runtime_error &e) {
		fmt::print(e.what());
	}
	fmt::print("\n\n");

	// Create a database
	BookDatabase myDB;
	myDB.addBook(myBook);
	myDB.addBook(anotherBook);
	myDB.addBook("America: A Concise History", "1828183632", "Snay", "Mitchell",
			"Denison Publish", 2014, Subject::Humanities);
	myDB.addBook("Sources for American History", "4123513492", "Authur",
			"Mitchell", "Princeton Uni", 2010, Subject::Humanities);

	try {
		myDB.addBook("Book", "1828183632", "A", "B", "B", 1, Subject::Humanities);
	} catch (runtime_error &e) {
		fmt::print(e.what());
		fmt::print("\n\n");
	}

	// Test database
	std::vector<Book> result = myDB.searchBookByName("HIstory");
	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	Book book = result[0];
	book.checkOut(myPatron);
	cout << book << endl << endl;

	// Test search by publisher
	result = myDB.searchBookByPublisher("denison");
	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	book = result[0];
	book.checkOut(myPatron);
	cout << book << endl << endl;

	// Test search by author
	result = myDB.searchBookByAuthor("Quan", "Mitchell");
	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	book = result[0];
	book.checkOut(myPatron);
	cout << book << endl << endl;
	*/

	LibraryCatalogApp myApp;
	myApp.start();
	myApp.createPatronRecord("D01711540", "Quan Tran");

	return 0;
}
