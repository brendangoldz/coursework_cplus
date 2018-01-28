#pragma once
#include <string>
using namespace std;
struct wind_t {
	int speed;
	string direction;
};
wind_t getWind();