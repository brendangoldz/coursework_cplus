#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "weather_measure.h"

using namespace std;
weathermeasure_t getMeasure() {
	weathermeasure_t result;
	result.temp = getTemp();
	result.wind = getWind();
	return result;
}