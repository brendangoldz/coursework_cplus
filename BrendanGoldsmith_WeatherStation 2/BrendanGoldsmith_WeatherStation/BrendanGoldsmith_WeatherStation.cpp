// BrendanGoldsmith_WeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
string name, str, dir[100];
int input, temp[100], wind[100];
string menu_re = "[1234]{1}";
int m = 0, n = -1;
string strName_re = "[a-zA-Z]{1,25}";
string temp_re = "[+-]?[0-9]{1,3}[fF]?";
string speed_re = "[0-9]{0,3}";
string dir_re = "[nNeEsSwW]{1,2}";

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
			<< "1. Input Weather Reading" << endl << "2. Print Current Weather" << endl << "3. Print weather history (Recent to Oldest)" << endl
			<< "4. Exit" << endl;
		getline(cin, str);
	} while (validate(str, menu_re) != true);
	stringstream(str) >> input;
	return input;
}
void print(int pos) {
		cout << endl << " The " << name << " Weather Station" << endl;
		cout << "Current Temperature (*F): " << temp[pos] << endl;
		cout << "Wind Speed & Direction: " << wind[pos] << " " << dir[pos] << endl;
}
int main()
{
				cout << "Please enter the weather station name: (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, strName_re) != true){
				cout << "Please enter the weather station name:" << endl << "Input must have at least one to twenty five characters, and cant contain numbers or symbols (Press ENTER when finished)" << endl;
		getline(cin, str);
	} 
	stringstream(str) >> name;

	do{
		input = menu();
	
	switch (input) {
		case 1:
					cout << "Please enter Current Temperature (*F):" << endl << "(Press ENTER when finished; Up to 999*F)" << endl;
				getline(cin, str);
				while (validate(str, temp_re) != true) {
					cout << "Bad input. Enter a Temperature from -999 to 999 degrees fahrenheit. Press ENTER when finished." << endl;
						getline(cin, str);
				}
				stringstream(str) >> temp[m];

					cout << "Please enter current Wind Speed: (Press ENTER when finished)" << endl;
				getline(cin, str);
				while (validate(str, speed_re) != true) {
					cout << "Bad input. Enter a Wind Speed from 0 to 999, miles per hour. Press ENTER when finished." << endl;
						getline(cin, str);
				}
				stringstream(str) >> wind[m];
			
					cout << "Please enter current wind direction (N, NW, S etc.): (Press ENTER when finished)" << endl;
				getline(cin, str);
				while (validate(str, dir_re) != true) {
					cout << "Bad input. Enter a Wind Direction using the letter notation; N for North, NW for NorthWest, S for South etc. Press ENTER when finished." << endl;
						getline(cin, str);
				}
				stringstream(str) >> dir[m];
				m++, n++;
			break;
		case 2:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else {
					print(n);
			}
			break;
		case 3:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else if (m > 4) {
				int limit = m - 4;
				for (int i = n; i >= limit; i--) {
					print(i);
				}
			}
			else {
				for (int i = n; i >= 0; i--) {
					print(i);
				}
			}
			break;
		case 4:
			exit(0);
			break;
		default:
				cout << "Input invalid, please try again.";
			break;
		
	}
	} while (input != 4);
	
    return 0;
}


