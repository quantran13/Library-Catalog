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

	void start();

	void checkOut();

	Patron& createPatronRecord(std::string patronID, std::string patronName);

	Book& addBook(); // TODO supply parameters

private:
	void readPatronDatabase();
	void readBookDatabase();

	BookDatabase mBookDatabase;
	PatronDatabase mPatronDatabase;
};

}
