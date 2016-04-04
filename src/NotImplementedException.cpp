//==============================================================================
// Quan Tran
// March 31, 2016
// exceptions.cpp
// Implementation file for the unimplemented exception.
//==============================================================================

#include <exceptions/NotImplementedException.h>

using namespace LibraryCatalog;

NotImplementedException::NotImplementedException():
	std::logic_error("Function not yet implemented!"),
	mMessage("Function not yet implemented!")
{
}

NotImplementedException::NotImplementedException(const std::string& message):
	std::logic_error(message),
	mMessage(message)
{
}

const char* NotImplementedException::what() const noexcept
{
	return mMessage.c_str();
}
