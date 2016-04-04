//==============================================================================
// Quan Tran
// April 3, 2016
// InvalidPatronID.h
// Header file for the invalid patron ID exception class.
//==============================================================================

#ifndef INVALIDPATRONID_H
#define INVALIDPATRONID_H

#include <stdexcept>
#include <string>

namespace LibraryCatalog {

class InvalidPatronID : public std::runtime_error {
public:
	InvalidPatronID();
	InvalidPatronID(const std::string& message);
	virtual const char* what() const noexcept override;

private:
	std::string mErrorMessage;

};

}

#endif
