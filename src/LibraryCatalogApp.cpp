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
}

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

	mPatronDatabase.addPatron(patronID, patronName);
	patronDatabaseFile.close();

	return mPatronDatabase.getPatronByID(patronID);
}

void LibraryCatalogApp::checkOut() 
{
	// TODO Checkout a book
}

//==============================================================================
// Functions for reading databases
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
