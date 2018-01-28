#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "temp.h"

using namespace std;
bool validate(string in, string val) {
	const char* test = in.c_str();
	regex re(val);
	cmatch match;
	if (regex_match(test, match, re)) {
		return true;
	}
	else {
		return false;
	}
}
temp_t getTemp() {
	temp_t result;
	string temp_re = "[+-]?[0-9]{1,3}[fF]?";
	string str;
	cout << "Please enter Current Temperature (*F):" << endl << "(Press ENTER when finished; Up to 999*F)" << endl;
	getline(cin, str);
	while (validate(str, temp_re) != true) {
		cout << "Bad input. Enter a Temperature from -999 to 999 degrees fahrenheit. Press ENTER when finished." << endl;
		getline(cin, str);
	}
	stringstream(str) >> result.temp;
	return result;
}