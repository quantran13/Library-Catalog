//==============================================================================
// Quan Tran
// March 17, 2016
// PatronDatabase.cpp
// Implementation for the patron database class
//==============================================================================

#include <PatronDatabase.h>

using namespace std;
using namespace utility;

namespace LibraryCatalog {

PatronDatabase::PatronDatabase()
{
	mNoPatron.setPatronID("D00000000");
}

Patron& PatronDatabase::addPatron(const string& patronID, const string& patronName)
{
	if (mPatrons.find(patronID) != mPatrons.end()) {
		// If the patron is already in the database
		throw runtime_error("Patron ID already existed in the database!");
	} else {
		// Make sure the ID's format is right
		if (!isValidPatronID(patronID))
			throw runtime_error("Wrong Patron ID format!");

		// Make sure the name is not empty
		if (patronName.length() == 0)
			throw runtime_error("Patron's name must not be empty!");

		// Add new patron to the Database
		Patron newPatron;
		newPatron.setPatronID(patronID);
		newPatron.setPatronName(patronName);

		mPatrons[patronID] = newPatron;

		return mPatrons[patronID];
	}
}

Patron& PatronDatabase::addPatron(const Patron& patron)
{
	if (mPatrons.find(patron.getPatronID()) != mPatrons.end()) {
		throw runtime_error("Patron ID already existed in the database!");
	} else {
		string patronID = patron.getPatronID();
		string patronName = patron.getPatronName();

		// Make sure the ID's format is right
		if (!isValidPatronID(patronID))
			throw runtime_error("Wrong Patron ID format!");

		// Make sure the name is not empty
		if (patronName.length() == 0)
			throw runtime_error("Patron's name must not be empty!");

		// Add new patron to the Database
		Patron newPatron(patronID, patronName);
		mPatrons[patronID] = newPatron;
		
		return mPatrons[patronID];
	}
}

vector<Patron> PatronDatabase::searchPatronByName(const string& patronName) const
{
	vector<Patron> patronsFoundList;
	// TODO Finish function

	return patronsFoundList;
}

Patron& PatronDatabase::getPatronByID(const string& patronID)
{
	if (mPatrons.find(patronID) != mPatrons.end())
		throw runtime_error("Patron not found!");
	else
		return mPatrons[patronID];
}
	
}
