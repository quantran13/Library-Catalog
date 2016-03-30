/*
 * BookDatabase.h
 *
 *  Created on: Feb 21, 2016
 *      Author: quan
 */

#ifndef BOOKDATABASE_H_
#define BOOKDATABASE_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Book.h>
#include <Constants.h>
#include <Patron.h>
#include <utility.h>

namespace LibraryCatalog {

class BookDatabase {
public:
	BookDatabase();
	virtual ~BookDatabase();

	/*
	 * Method: addBook
	 * Usage: addBook(bookName, ISBN, authorFirstName, authorLastName,
	 *                publisher, yearOfPublication, subject)
	 * -------------------------------------------------------------------------
	 * Add a book to the database by creating a book object with the data
	 * provided then add it to the vector.
	 */
	Book& addBook(const std::string bookName, const std::string ISBN,
				  const std::string authorFirstName, const std::string authorLastName,
				  const std::string publisher, int yearOfPublication, Subject subject);

	/*
	 * Method: addBook.
	 * Usage: addBook(book)
	 * -------------------------------------------------------------------------
	 * Add a book object to the database's vector.
	 */
	Book& addBook(Book book);

	/*
	 * Method: searchBookByName
	 * Usage: searchBookByName(bookName)
	 * -------------------------------------------------------------------------
	 * Search a book in the database using the book's name provided.
	 */
	std::vector<Book> searchBookByName(std::string bookName);

	/*
	 * Method: searchBookByAuthor
	 * Usage: searchBookByAuthor(authorFirstName, authorLastName)
	 * -------------------------------------------------------------------------
	 * Search a book in the database based on the author's name provided.
	 */
	std::vector<Book> searchBookByAuthor(std::string authorFirstName,
										 std::string authorLastName);

	/*
	 * Method: searchBookByPublisher
	 * Usage: searchBookByPublisher(publisher)
	 * -------------------------------------------------------------------------
	 * Search a book in the database using the publisher's name provided.
	 */
	std::vector<Book> searchBookByPublisher(std::string publisher);

	/*
	 * Method: getBookByISBN
	 * Usage: getBookByISBN(ISBN)
	 * -------------------------------------------------------------------------
	 * Get a book by its ISBN.
	 */
	Book& getBookByISBN(const std::string ISBN);

private:
	std::map<std::string, Book> mBooks;
	Book mNoBook;
};

/*
 * TODO add comment
 */
BookDatabase operator+(BookDatabase db1, BookDatabase db2);

} /* namespace LibraryCatalog */

#endif /* BOOKDATABASE_H_ */
