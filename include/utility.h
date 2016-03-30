/*
 * utility.h
 *
 *  Created on: Feb 23, 2016
 *      Author: quan
 *
 * Simple string functions
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>
#include <vector>
#include <stdexcept>

namespace utility {

std::string lower(std::string inputStr);
std::vector<std::string> split(std::string text, std::string seperators);

bool isValidPatronID(std::string patronID);

}



#endif 
