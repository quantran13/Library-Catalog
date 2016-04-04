//==============================================================================
// Quan Tran
// Mar 16, 2016
// LibraryCatalogApp.h
// Header file for the Library Catalog app class
//==============================================================================

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <Book.h>
#include <BookDatabase.h>
#include <Patron.h>
#include <PatronDatabase.h>
#include <exceptions/NotImplementedException.h>
#include <utility.h>
#include <format.h>

namespace LibraryCatalog {

class LibraryCatalogApp
{
public:
	LibraryCatalogApp();

	/*
	 * Method: start
	 * Usage: start()
	 * -------------------------------------------------------------------------
	 * Reads the databases and opens up the user interface, waiting for user 
	 * input.
	 */
	void start();

	/*
	 * Method: checkOut
	 * Usage: checkOut(patronID, bookISBN)
	 * -------------------------------------------------------------------------
	 * Checks out a book for a specified patron.
	 * Throws a invalid patronID exception if the given patron ID is invalid.
	 */
	void checkOut(std::string patronID, std::string bookISBN);

	Patron& createPatronRecord(std::string patronID, std::string patronName);

	Book& addBook(std::string bookISBN, std::string bookName,
	              std::string authorFirstName, std::string authorLastName,
				  std::string publisher, int yearOfPublication, Subject subject); 

private:
	void readPatronDatabase();
	void readBookDatabase();

	BookDatabase mBookDatabase;
	PatronDatabase mPatronDatabase;
};

}
