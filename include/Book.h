/*
 * Book.h
 *
 *  Created on: Feb 18, 2016
 *      Author: quan
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string>
#include <Constants.h>
#include <Patron.h>

namespace LibraryCatalog {

class Book {
public:
	Book();
	Book(const std::string bookName, const std::string ISBN,
			const std::string authorFirstName, const std::string authorLastName,
			const std::string publisher, int yearOfPublication, Subject subject);
	virtual ~Book();

	//==========================================================================
	// Getters & Setters
	//==========================================================================

	void setBookName(const std::string bookName);
	std::string getBookName() const;

	void setISBN(const std::string ISBN);
	std::string getISBN() const;

	void setAuthorFirstName(const std::string authorFirstName);
	std::string getAuthorFirstName() const;

	void setAuthorLastName(const std::string authorLastName);
	std::string getAuthorLastName() const;

	void setPublisher(const std::string publisher);
	std::string getPublisher() const;

	void setSubject(Subject subject);
	std::string getSubject() const;

	void setYearOfPublication(const int year);
	int getYearOfPublication() const;

	void setBookStatus(BookStatus bookStatus);
	BookStatus getBookStatus() const;

	//==========================================================================
	// Book status changing functions
	//==========================================================================

	/*
	 * Method: checkOut
	 * Usage: checkOut(patron)
	 * -------------------------------------------------------------------------
	 * Try checking out if book is available and return
	 * whether book has been checked out successfully or not.
	 */
	std::string checkOut(Patron patron);

	/*
	 * Method: checkIn
	 * Usage: checkIn()
	 * -------------------------------------------------------------------------
	 * Check in the book and return whether the book is checked in successfully
	 * or not.
	 */
	bool checkIn();

	/*
	 * Method: reserve
	 * Usage: reserve(patron)
	 * -------------------------------------------------------------------------
	 * Reserve the book and return whether the book is reserved successfully
	 * or not.
	 */
	std::string reserve(Patron patron);

	/*
	 * Method: cancelReserve
	 * Usage: cancelReserve(patron)
	 * -------------------------------------------------------------------------
	 * Cancel the book's reservation and return a message.
	 */
	std::string cancelReserve(Patron patron);

	/* Method: display
	 * Usage: display()
	 * -------------------------------------------------------------------------
	 * Display the book's information.
	 */
	std::string display() const;

private:
	/* Book information */
	std::string mBookName;
	std::string mISBN;
	std::string mAuthorFirstName;
	std::string mAuthorLastName;
	std::string mPublisher;
	Subject mSubject;
	int mYearOfPublication;

	/* Book status */
	BookStatus mBookStatus;
	Patron mBookPatron;
	Patron mNoPatron;
};

/*
 * Overloading operator =
 */
std::ostream& operator<<(std::ostream & os, Book book);

} /* namespace LibraryCatalog */

#endif /* BOOK_H_ */
