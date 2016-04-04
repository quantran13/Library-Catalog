/*
 * Book.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: quan
 */

#include <Book.h>

using namespace std;

namespace LibraryCatalog {

Book::Book()
{
	mBookName = "";
	mISBN = "";
	mAuthorFirstName = "";
	mAuthorLastName = "";
	mPublisher = "";
	mYearOfPublication = 0;
	mSubject = Subject::None;

	mBookStatus = BookStatus::Available;

	mNoPatron.setPatronID("D0000000");
	mNoPatron.setPatronName("");
	mBookPatron = mNoPatron;
}

Book::Book(const string bookName, const string ISBN,
		const string authorFirstName, const string authorLastName,
		const string publisher, int yearOfPublication, Subject subject)
{
	mBookName = bookName;
	mISBN = ISBN;
	mAuthorFirstName = authorFirstName;
	mAuthorLastName = authorLastName;
	mPublisher = publisher;
	mYearOfPublication = yearOfPublication;
	mSubject = subject;

	mBookStatus = BookStatus::Available;
	mNoPatron.setPatronID("D0000000");
	mNoPatron.setPatronName("");
	mBookPatron = mNoPatron;

}

Book::~Book() {
	// Nothing to clean up.
}

//==============================================================================
// Getters & Setters for Book's properties.
//==============================================================================

void Book::setBookName(const string bookName)
{
	mBookName = bookName;
}

string Book::getBookName() const
{
	return mBookName;
}

void Book::setISBN(const string ISBN)
{
	mISBN = ISBN;
}

string Book::getISBN() const
{
	return mISBN;
}

void Book::setAuthorFirstName(const string authorFirstName)
{
	mAuthorFirstName = authorFirstName;
}

string Book::getAuthorFirstName() const
{
	return mAuthorFirstName;
}

void Book::setAuthorLastName(const string authorLastName)
{
	mAuthorLastName = authorLastName;
}

string Book::getAuthorLastName() const
{
	return mAuthorLastName;
}

void Book::setPublisher(const string publisher)
{
	mPublisher = publisher;
}

string Book::getPublisher() const
{
	return mPublisher;
}

void Book::setSubject(Subject subject)
{
	mSubject = subject;
}

string Book::getSubject() const
{
	switch (mSubject) {
		case Subject::FineArts:
			return "Fine Arts";
		case Subject::Humanities:
			return "Humanities";
		case Subject::Interdisciplinary:
			return "Interdisciplinary";
		case Subject::NaturalScience:
			return "Natural Science";
		case Subject::SocialScience:
			return "Social Science";
		case Subject::None:
			return "None";
	}

	return "None";
}

void Book::setYearOfPublication(int year)
{
	mYearOfPublication = year;
}

int Book::getYearOfPublication() const
{
	return mYearOfPublication;
}

void Book::setBookStatus(BookStatus bookStatus)
{
	mBookStatus = bookStatus;
}

BookStatus Book::getBookStatus() const
{
	return mBookStatus;
}

//==============================================================================
// Book status changing functions
//==============================================================================

void Book::checkOut(const Patron& patron)
{
	if (getBookStatus() == BookStatus::CheckedOut) {
		string message = "The book is already checked out!";
		throw runtime_error(message);
	} else if (getBookStatus() == BookStatus::Reserved) {
		if (patron.getPatronID() == mBookPatron.getPatronID()) {
			setBookStatus(BookStatus::CheckedOut);
			mBookPatron = patron;
		} else {
			string message = "The book is reserved!";
			throw runtime_error(message);
		}
	} else {
		mBookPatron = patron;
		setBookStatus(BookStatus::CheckedOut);
	}
}

bool Book::checkIn()
{
	if (getBookStatus() == BookStatus::CheckedOut) {
		setBookStatus(BookStatus::Available);
		mBookPatron = mNoPatron;
		return true;
	}

	mBookPatron = mNoPatron;
	return false;
}

void Book::reserve(const Patron& patron)
{
	if (getBookStatus() == BookStatus::Reserved) {
		string message = "The book is already reserved!";
		throw runtime_error(message);
	} else if (getBookStatus() == BookStatus::CheckedOut) {
		string message = "The book is checked out!";
		throw runtime_error(message);
	} else {
		mBookPatron = patron;
		mBookStatus = BookStatus::Reserved;
	}
}

void Book::cancelReserve(const Patron& patron)
{
	if (getBookStatus() == BookStatus::Reserved) {
		if (patron.getPatronID() == mBookPatron.getPatronID()) {
			setBookStatus(BookStatus::Available);
		} else {
			throw runtime_error("You cannot cancel the reservation on this book!");
		}
	} else {
		string message = "No reservation at the moment to be cancelled.";
		throw runtime_error(message);
	}
}

//==============================================================================
// Book information displaying function
//==============================================================================

string Book::display() const
{
	cout << getBookName() << endl;
	cout << "ISBN:      " << getISBN() << endl;
	cout << "Author:    " << getAuthorLastName() << ", " << getAuthorFirstName();
	cout << endl << "Publisher: " << getPublisher() << ", ";
	cout << getYearOfPublication() << endl;

	string bookStatus = "Status:    ";
	if (getBookStatus() == BookStatus::Available)
		bookStatus += "Available.";
	else if (getBookStatus() == BookStatus::CheckedOut)
		bookStatus += "Checked out to " + mBookPatron.getPatronName() + ".";
	else
		bookStatus += "Reserved to " + mBookPatron.getPatronName() + ".";

	return bookStatus;
}

ostream& operator<<(ostream & os, Book book)
{
	os << book.display();
	return os;
}


} /* namespace LibraryCatalog */






