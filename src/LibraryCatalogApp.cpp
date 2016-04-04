//==============================================================================
// Quan Tran
// Mar 16, 2016
// LibraryCatalogApp.cpp
// Implementation for the Library Catalog app class
//==============================================================================

#include <LibraryCatalogApp.h>

using namespace std;
using namespace utility;

namespace LibraryCatalog {

//==============================================================================
// Constructors & App starting function
//==============================================================================
LibraryCatalogApp::LibraryCatalogApp()
{
	// TODO constructor
	mPatronDatabase.addPatron("D00000000", "Admin");
}


void LibraryCatalogApp::start()
{
	readPatronDatabase();

	// TODO Try creating patron + read patron db
	Patron quan = mPatronDatabase.getPatronByID("D01711540");
	cout << quan << endl;

	// Main part
	fmt::print("Welcome to the Denison University's Library Catalog!\n");

	while (true) {
		int options = 7;

		fmt::print("\n------------------------------------------------------\n");
		fmt::print("1. Check out a book.\n");
		fmt::print("2. Check in a book.\n");
		fmt::print("3. Reserve a book.\n");
		fmt::print("\n4. Create a new Patron record.\n");
		fmt::print("\n5. Delete a patron from the database.\n");
		fmt::print("\n6. Add a book to the database.\n");
		fmt::print("\n7. Quit.\n");

		fmt::print("\n");
		int userOption = 0;
		while (userOption <= 0 || userOption > options) {
			cin >> userOption;
		}

		switch (userOption) {
		case 1:
		{
			/* Check out a book */

			// Read the patron ID.
			string patronID;
			cout << "Input your patron ID: ";
			cin >> patronID;

			// Read the book's ISBN number.
			string bookISBN;
			cout << "Input your book ISBN: ";
			cin >> bookISBN;

			try {
				checkOut(patronID, bookISBN);
			} catch (InvalidPatronID& e) {
				cout << e.what() << endl;
			} catch (runtime_error& e) {
				cout << e.what() << endl;
			}
			
			break;
		}
		case 2:
			throw NotImplementedException();
			break;
		case 3:
			throw NotImplementedException();
			break;
		case 4:
			throw NotImplementedException();
			break;
		case 5:
			throw NotImplementedException();
			break;
		case 6:
			throw NotImplementedException();
			break;
		case 7:
		default:
			cout << "7" << endl;
		}

		if (userOption == options) // If the option is the last one then quits.
			break;
	}
}


//==============================================================================
// Create patron record
//==============================================================================

Patron& LibraryCatalogApp::createPatronRecord(string patronID, string patronName)
{
	Patron newPatron;
	newPatron.setPatronName(patronName);
	newPatron.setPatronID(patronID);

	// Write patron info to database file
	ofstream patronDatabaseFile;
	patronDatabaseFile.open("patrons.db", ios::app);
	if (patronDatabaseFile.is_open())
		patronDatabaseFile << patronID << ", " << patronName << "\n";
	else
		throw runtime_error("Could not open patrons database file!");

	// Add patron to the database
	patronDatabaseFile.close();

	try {
		mPatronDatabase.addPatron(patronID, patronName);
	} catch (runtime_error& e) {
		throw runtime_error(e.what());
	}

	return mPatronDatabase.getPatronByID(patronID);
}


//==============================================================================
// Check out a book
//==============================================================================

void LibraryCatalogApp::checkOut(string patronID, string bookISBN) 
{
	Patron patronFound;
	if (!isValidPatronID(patronID))
		throw InvalidPatronID(patronID);
	else
		patronFound = mPatronDatabase.getPatronByID(patronID);
	
	Book bookFound;
	try {
		bookFound = mBookDatabase.getBookByISBN(bookISBN);
	} catch (runtime_error& e) {
		throw runtime_error(e.what());
	}

	if (bookFound.getBookStatus() == BookStatus::Available)
		cout << "Available\n";
	else
		cout << "Not available\n";

	try {
		bookFound.checkOut(patronFound);
	} catch (runtime_error& e) {
		throw runtime_error(e.what());
	}
}


//==============================================================================
// Add a book to the database
//==============================================================================

Book& LibraryCatalogApp::addBook(string bookISBN, string bookName,
                                 string authorFirstName, string authorLastName,
								 string publisher, int yearOfPublication,
								 Subject subject)
{
	Book newBook(bookName, bookISBN, authorFirstName, authorLastName, publisher,
	             yearOfPublication, subject);

	// TODO Write book info to database file
	
	// Add book the the database
	try {
		mBookDatabase.addBook(newBook);
	} catch (runtime_error& e) {
		throw runtime_error(e.what());
	}

	return mBookDatabase.getBookByISBN(bookISBN);
}

//==============================================================================
// Read in the database file
//==============================================================================

void LibraryCatalogApp::readPatronDatabase() 
{
	fstream patronDatabaseFile;
	patronDatabaseFile.open("patrons.db", ios::trunc | ios::in | ios::out);

	if (patronDatabaseFile.is_open()) {
		string line;

		while (getline(patronDatabaseFile, line)) {
			vector<string> patronInfo = utility::split(line, " ,.");
			if (patronInfo.size() != 2)
				continue;

			// Check for patronID's format
			string patronID = patronInfo[0];
			if (!isValidPatronID(patronID)) {} // TODO Write to log file

			// Check for patronName
			string patronName = patronInfo[1];
			if (patronName.length() == 0) {} // TODO write to log file

			Patron newPatron;
			newPatron.setPatronID(patronID);
			newPatron.setPatronName(patronName);

			mPatronDatabase.addPatron(newPatron);

			patronDatabaseFile.close();
		}
	} else
		throw runtime_error("Could not open patron database file for input!");
}

void LibraryCatalogApp::readBookDatabase() 
{
	// TODO
}

}
