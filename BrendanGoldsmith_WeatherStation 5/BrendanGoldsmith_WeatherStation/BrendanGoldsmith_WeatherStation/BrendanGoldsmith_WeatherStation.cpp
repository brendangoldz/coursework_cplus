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
string menu_re = "[123]{1}";

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
int menu() {
	do {
		cout << name << " Weather Station Dashboard. Enter number to select option from menu: " << endl
			<< "1. Input Weather Reading" << endl << "2. Print Current Weather" << endl << "3. Print Weather History" << "4. Exit" << endl;
		getline(cin, str);
	} while (validate(str, menu_re) != true);
	stringstream(str) >> input;
	return input;
}
int main()
{
	string strName_re = "[a-zA-Z]{1,25}";
	string temp_re = "[+-]?[0-9]{1,2}[fF]?";
	string speed_re = "[0-9]{1,2}";
	string dir_re = "[nNeEsSwW]{1,2}";
	int n = 0;
	cout << "Please enter the weather station name: (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, strName_re) != true){
		cout << "Please enter the weather station name:" << endl << "Input must have at least one to twenty five characters, and cant contain numbers or syymbols (Press ENTER when finished)" << endl;
		getline(cin, str);
	} 
	stringstream(str) >> name;
	do{
		input = menu();
	
	switch (input) {
		case 1:
				cout << "Please enter Current Temperature (*F):" << endl << "(Press ENTER when finished; Up to 99*)" << endl;
				getline(cin, str);
				while (validate(str, temp_re) != true) {
					cout << "Bad input. Enter a Temperature from -99 to 99 degrees fahrenheit. Press ENTER when finished." << endl;
						getline(cin, str);
				}
				stringstream(str) >> temp;

				cout << "Please enter current Wind Speed: (Press ENTER when finished)" << endl;
				getline(cin, str);
				while (validate(str, speed_re) != true) {
					cout << "Bad input. Enter a Wind Speed from 0 to 99, miles per hour. Press ENTER when finished." << endl;
						getline(cin, str);
				}
					stringstream(str) >> wind;
			
				cout << "Please enter current wind direction (N, NW, S etc.): (Press ENTER when finished)" << endl;
				getline(cin, str);
				while (validate(str, dir_re) != true) {
					cout << "Bad input. Enter a Wind Direction using the letter notation; N for North, NW for NorthWest, S for South etc. Press ENTER when finished." << endl;
						getline(cin, str);
				}
				stringstream(str) >> dir;
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
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Input invalid, please try again.";
			break;
		
	}
	} while (input != 3);
	
    return 0;
}


