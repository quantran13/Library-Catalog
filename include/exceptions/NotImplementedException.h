//==============================================================================
// Quan Tran
// March 31, 2016
// exceptions.h
// Header file for the unimplemented exception.
//==============================================================================

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

namespace LibraryCatalog {

class NotImplementedException : public std::logic_error {
public:
	NotImplementedException();
	NotImplementedException(const std::string& message);
	virtual const char* what() const noexcept override;

private:
	std::string mMessage;
};

}

#endif
