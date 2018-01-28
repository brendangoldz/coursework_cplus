// BrendanGoldsmith_WeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
string name, str, dir;
int input, temp, wind;
int menu() {
	cout << name << " Weather Station Dashboard. Enter number to select option from menu: " << endl
		<< "1. Input Weather Reading" << endl << "2. Print Current Weather" << endl << "3. Exit" << endl;
	getline(cin, str);
	stringstream(str) >> input;
	return input;
}
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

int main()
{
	string strName_re = "[a-zA-Z]{2,}";
	string temp_re = "[+-]?[0-9]{2}[cCfF]?";
	string speed_re = "[0-9]{3}";
	string dir_re = "[nNeEsSwW]{0,2}";
	int n = 0;
	cout << "Please enter the weather station name: (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, strName_re) != true){
		cout << "Please enter the weather station name:" << endl << "Input must have at least one character, and cant contain numbers or syymbols (Press ENTER when finished)" << endl;
		getline(cin, str);
	} 
	stringstream(str) >> name;
	do{
		input = menu();
	
	switch (input) {
		case 1:
			cout << "Please enter Current Temperature: (Press ENTER when finished)" << endl;
			getline(cin, str);
			if(validate(str, temp_re)) stringstream(str) >> temp;
			else cout << "Bad input" << endl;
			cout << "Please enter current Wind Speed: (Press ENTER when finished)" << endl;
			getline(cin, str);
			if(validate(str, speed_re))	stringstream(str) >> wind;
			else cout << "Bad input" << endl;
			cout << "Please enter current wind direction (N, NW, S etc.): (Press ENTER when finished)" << endl;
			getline(cin, str);
			if(validate(str,dir_re)) stringstream(str) >> dir;
			else cout << "Bad input" << endl;
			n++;
			break;
		case 2:
			if (n == 0) {
				cout << "No Weather Reading Available" << endl;
				break;
			}
			else {
				cout << "The " << name << " Weather Station" << endl;
				cout << "Current Temperature (*F): " << temp << endl;
				cout << "Wind Speed & Direction: " << wind << " " << dir << endl;
				break;
			}
		case 3:
			exit(0);
			break;
		default:
			cout << "Input invalid, please try again.";
			break;
		
	}
	} while (input != 3);
	
    return 0;
}


