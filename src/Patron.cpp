/*
 * Patron.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: quan
 */

#include <Patron.h>

using namespace std;

namespace LibraryCatalog {

Patron::Patron() 
{
}

Patron::Patron(const string& patronID, const string& patronName)
{
	if (!utility::isValidPatronID(patronID))
		throw runtime_error("Invalid patron ID!");
	
	if (patronName == "")
		throw runtime_error("Patron's name must not be empty!");

	mPatronID = patronID;
	mPatronName = patronName;
}

Patron::~Patron()
{
}

void Patron::setPatronName(string name)
{
	mPatronName = name;
}

string Patron::getPatronName() const
{
	return mPatronName;
}

void Patron::setPatronID(string id)
{
	mPatronID = id;
}

string Patron::getPatronID() const
{
	return mPatronID;
}

string Patron::display() const
{
	string patronInfo = "";
	patronInfo += getPatronName();
	patronInfo += " - " + getPatronID() + "\n";

	return patronInfo;
}

ostream& operator<<(ostream& os, const Patron& patron)
{
	os << patron.display();

	return os;
}


} /* namespace LibraryCatalog */
