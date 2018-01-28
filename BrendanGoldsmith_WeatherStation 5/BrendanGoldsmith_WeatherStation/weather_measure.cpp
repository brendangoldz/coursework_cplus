#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "weather_measure.h"

using namespace std;
class MeasureWeather {
	weathermeasure_t result;
	Wind w; Temp t;
	weathermeasure_t MeasureWeather::getMeasure() {
		result.temp = t.getTemp();
		result.wind = w.getWind();
		return result;
	}
};