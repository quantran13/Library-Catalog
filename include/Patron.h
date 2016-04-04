/*
 * Patron.h
 *
 *  Created on: Feb 19, 2016
 *      Author: quan
 */

#ifndef PATRON_H_
#define PATRON_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <exceptions/InvalidPatronID.h>
#include <utility.h>

namespace LibraryCatalog {

class Patron {
public:
	Patron();
	Patron(const std::string& patronID, const std::string& patronName);
	virtual ~Patron();

	/* Getters & Setters */
	void setPatronName(std::string name);
	std::string getPatronName() const;

	void setPatronID(std::string id);
	std::string getPatronID() const;

	// Patron info displaying function
	std::string display() const;

private:
	std::string mPatronName;
	std::string mPatronID;
};

std::ostream& operator<<(std::ostream & os, const Patron& patron);

} /* namespace LibraryCatalog */

#endif /* PATRON_H_ */
