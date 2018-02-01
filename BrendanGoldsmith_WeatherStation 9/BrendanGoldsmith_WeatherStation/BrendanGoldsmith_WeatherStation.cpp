// BrendanGoldsmith_WeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "weather_measure.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

int m = 0, n = -1, x = 1;
//m = array size counter; n = position counter; x = max array size (input)
string name, str;
int input;
string menu_re = "[1234]{1}";
string strName_re = "[a-zA-Z]{1,25}";
string size_re = "[2-9]{1,99}";

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
void insert(weathermeasure_t * test) {
	for (int i = m; i > 0; i--) {
		test[i] = test[i - 1];
	}
	test[0] = getMeasure();
	m++, n++;
}
void print(weathermeasure_t * n4, int a) {

	if (a == 0) {
		cout << endl << " The " << name << " Weather Station" << endl;
		cout << "Current Temperature (*F): " << n4[0].temp.temp << endl;
		cout << "Wind Speed & Direction: " << n4[0].wind.speed << n4[0].wind.direction <<endl;
	}
	else {
		if (m < x) {
			for (int j = 0; j < m ; j++) {
				cout << endl << " The " << name << " Weather Station" << endl;
				cout << "Current Temperature (*F): " << n4[j].temp.temp << endl;
				cout << "Wind Speed & Direction: " << n4[j].wind.speed << " " << n4[j].wind.direction << endl;
			}
		}
		else {
			for (int j = 0; j < x; j++) {
				cout << endl << " The " << name << " Weather Station" << endl;
				cout << "Current Temperature (*F): " << n4[j].temp.temp << endl;
				cout << "Wind Speed & Direction: " << n4[j].wind.speed << " " << n4[j].wind.direction << endl;
			}
		}
	}
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
				cout << "Please enter how many weather inputs you would like to input: (Press ENTER when finished)" << endl;
	getline(cin, str);
	while (validate(str, size_re) != true) {
		cout << "Please enter how many weather inputs you would like to input: (Press ENTER when finished)" << endl << "Input must be more than 2, positive and an integer (Press ENTER when finished)" << endl;
		getline(cin, str);
	}
	stringstream(str) >> x;

	struct weathermeasure_t * pmeasure = new weathermeasure_t[x];


	do{
		input = menu();
		switch (input) {
		case 1:
			insert(pmeasure);
			break;
		case 2:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else {
				print(pmeasure, 0);
			}
			break;
		case 3:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else {
				print(pmeasure, x);
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
	delete[] pmeasure;
    return 0;
}




