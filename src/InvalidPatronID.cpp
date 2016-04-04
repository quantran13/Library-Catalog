//==============================================================================
// Quan Tran
// April 3, 2016
// InvalidPatronID.h
// Implementation file for the invalid patron ID exception class.
//==============================================================================

#include <exceptions/InvalidPatronID.h>

using namespace LibraryCatalog;

InvalidPatronID::InvalidPatronID():
	std::runtime_error("Invalid Patron ID format!"),
	mErrorMessage("Invalid Patron ID format!")
{
}

InvalidPatronID::InvalidPatronID(const std::string& message):
	std::runtime_error("Invalid Patron ID format" + message),
	mErrorMessage("Invalid Patron ID format" + message)
{
}

const char* InvalidPatronID::what() const noexcept
{
	return mErrorMessage.c_str();
}
