#pragma once
#include <string>
using namespace std;
struct wind_t {
	int speed;
	string dir;
};

class Wind {
public:
	wind_t w;
	wind_t getWind();
};