/*
 * Constants.h
 * 
 * Author: Quan Tran
 * Constants for the project.
 */

 #ifndef CONSTANTS_H_
 #define CONSTANTS_H_

namespace LibraryCatalog {

enum class Subject {
	None,
	NaturalScience,
	SocialScience,
	Humanities,
	FineArts,
	Interdisciplinary
};

enum class BookStatus {
	Available,
	CheckedOut,
	Reserved
};

namespace Constants {
	// Constants go here
}

}



#endif 
