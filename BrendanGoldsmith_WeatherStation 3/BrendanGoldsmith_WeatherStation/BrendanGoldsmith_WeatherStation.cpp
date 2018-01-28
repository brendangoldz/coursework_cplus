// BrendanGoldsmith_WeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "weather_measure.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

int m = 0, n = -1, x = 1;
//m = array size counter; n = position counter; x = max array size (input)
string name, str;
int input;
int * speed, * temp;
string * dir;
string menu_re = "[1234]{1}";
string strName_re = "[a-zA-Z]{1,25}";

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
void insert(int * n5, int * n6, string * n7) {

	if (m > 0) {
		if (m < x) {
			for (int i = m; i > 0; i--) {
				n7[i] = n7[i - 1];
				n5[i] = n5[i - 1];
				n6[i] = n6[i - 1];
			}
		}
		else {
			for (int i = (x - 1); i > 0; i--) {
				n7[i] = n7[i - 1];
				n5[i] = n5[i - 1];
				n6[i] = n6[i - 1];
			}
		}
	}
	else {
		for (int i = (m + 1); i > 0; i--) {
			n7[i] = n7[i - 1];
			n5[i] = n5[i - 1];
			n6[i] = n6[i - 1];
		}
	}
	m++, n++;
}
void print(int* n2, int* n3, string* n4, int a) {
	if (a == 0) {
		cout << endl << " The " << name << " Weather Station" << endl;
		cout << "Current Temperature (*F): " << n2[0] << endl;
		cout << "Wind Speed & Direction: " << n3[0] << " " << n4[0] << endl;
	}
	else {
		if (m < x) {
			for (int j = 0; j < m ; j++) {
				cout << endl << " The " << name << " Weather Station" << endl;
				cout << "Current Temperature (*F): " << n2[j] << endl;
				cout << "Wind Speed & Direction: " << n3[j] << " " << n4[j] << endl;
			}
		}
		else {
			for (int j = 0; j < x; j++) {
				cout << endl << " The " << name << " Weather Station" << endl;
				cout << "Current Temperature (*F): " << n2[j] << endl;
				cout << "Wind Speed & Direction: " << n3[j] << " " << n4[j] << endl;
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
	stringstream(str) >> x;

	speed = new int[x];
	temp = new int[x];
	dir = new string[x];

	do{
		input = menu();
		switch (input) {
		case 1:
			insert(temp, speed, dir);
			break;
		case 2:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else {
				print(temp, speed, dir, 0);
			}
			break;
		case 3:
			if (m == 0) {
					cout << "No Weather Reading Available" << endl;
			}
			else {
				print(temp, speed, dir, x);
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
	delete[] dir;
	delete[] temp;
	delete[] speed;
    return 0;
}




