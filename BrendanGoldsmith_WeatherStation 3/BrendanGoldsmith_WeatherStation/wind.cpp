#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "wind.h"

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
wind_t getWind() {
	string str;
	wind_t result;
	string speed_re = "[0-9]{0,3}";
	string dir_re = "[nNeEsSwW]{1,2}";
	cout << "Please enter current Wind Speed: (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, speed_re) != true) {
		cout << "Bad input. Enter a Wind Speed from 0 to 999, miles per hour. Press ENTER when finished." << endl;
		getline(cin, str);
	}
	stringstream(str) >> result.speed;

	cout << "Please enter current wind direction (N, NW, S etc.): (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, dir_re) != true) {
		cout << "Bad input. Enter a Wind Direction using the letter notation; N for North, NW for NorthWest, S for South etc. Press ENTER when finished." << endl;
		getline(cin, str);
	}
	stringstream(str) >> result.direction;
	return result;
}