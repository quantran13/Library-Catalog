/*
 * utility.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: quan
 */

#include <utility.h>

using namespace std;

namespace utility {

string lower(string inputStr)
{
	string result = "";

	for (unsigned int i = 0; i < inputStr.length(); i++) {
		char c = inputStr[i];

		if (inputStr[i] >= 'A' && inputStr[i] <= 'Z') {
			c = c + 32;
		}

		result += c;
	}

	return result;
}

vector<string> split(string text, string seperator)
{
	vector<string> wordList;
	size_t i = 0;

	if (text.length() == 0)
		return wordList;

	while (i < text.length() - 1) {
		string tempWord= "";
		bool found = false;

		/* Skip the seperation characters */
		while (seperator.find(text[i]) != string::npos)
			i++;

		/* Find the next word up to the next seperation character */
		while (i < text.length() && seperator.find(text[i]) == string::npos) {
			found = true;
			tempWord += text[i];
			i++;
		}

		if (found) wordList.push_back(tempWord);
	}

	return wordList;
}

bool isValidPatronID(string patronID)
{
	if (patronID.length() != 9)
		return false;

	if (patronID[0] != 'D')
		return false;
	
	for (size_t i = 1; i < patronID.length(); i++)
		if (patronID[i] < '0' || patronID[i] > '9')
			return false;
	
	return true;
}


}


