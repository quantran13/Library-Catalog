//==============================================================================
// Quan Tran
// Mar 16, 2016
// LibraryCatalogApp.h
// Header file for the Library Catalog app class
//==============================================================================

#include <fstream>
#include <stdexcept>
#include <Book.h>
#include <BookDatabase.h>
#include <Patron.h>
#include <PatronDatabase.h>
#include <utility.h>
#include <format.h>

namespace LibraryCatalog {

class LibraryCatalogApp
{
public:
	LibraryCatalogApp();

	/*
	 * TODO write comment
	 */
	void start();

	/*
	 * TODO Write comment
	 */
	Patron& createPatronRecord(std::string patronID, std::string patronName);

	/*
	 * TODO write comment
	 */
	Book& addBook(); // TODO supply parameters

private:
	void checkOut();
	void readPatronDatabase();
	void readBookDatabase();

	BookDatabase mBookDatabase;
	PatronDatabase mPatronDatabase;
};

}
