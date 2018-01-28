#include "temp.h"
#include "wind.h"
using namespace std;

struct weathermeasure_t {
	wind_t wind;
	int temp;
};
class MeasureWeather {
public:
	
	weathermeasure_t getMeasure();
};