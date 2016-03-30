//==============================================================================
// Quan Tran
// March 17, 2016
// PatronDatabase.h
// Header file for the patron database class
//==============================================================================

#ifndef PATRONDATABASE_H_
#define PATRONDATABASE_H_

#include <map>
#include <string>
#include <vector>
#include <utility.h>
#include <Patron.h>

namespace LibraryCatalog {

class PatronDatabase {
public:
	PatronDatabase();

	/*
	 * Method: addPatron
	 * Usage: addPatron(patronID, patronName)
	 * -------------------------------------------------------------------------
	 * Add a patron with the given information to the database, and return the 
	 * patron object in the database.
	 *
	 * Throw a runtime_error if the patronID is invalid, or the patronName is 
	 * empty.
	 */
	Patron& addPatron(const std::string& patronID, const std::string& patronName);

	/*
	 * Method: addPatron
	 * Usage: addPatron(patron)
	 * -------------------------------------------------------------------------
	 * Add the given patron object to the database, and return the patron object
	 * in the database.
	 *
	 * Throw a runtime_error if the patronId is invalid, or the patronName is 
	 * empty.
	 */
	Patron& addPatron(const Patron& patron);

	/*
	 * Method: searchPatronByName
	 * Usage: searchPatronByName(patronName)
	 * -------------------------------------------------------------------------
	 * Search the database using the given name and return a vector containing 
	 * the matched patrons.
	 */
	std::vector<Patron> searchPatronByName(const std::string& patronName) const;

	/*
	 * Method: getPatronByID
	 * Usage: searchPatronByID(patronID)
	 * -------------------------------------------------------------------------
	 * Get the patron by the ID and return the patron object. Throw a runtime
	 * error if no patron is found with the given ID
	 */
	Patron& getPatronByID(const std::string& patronID);

private:
	std::map<std::string, Patron> mPatrons;
	Patron mNoPatron;
};

}

#endif
