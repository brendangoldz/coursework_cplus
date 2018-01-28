#include "temp.h"
#include "wind.h"
using namespace std;

struct weathermeasure_t {
	wind_t wind;
	temp_t temp;
};
weathermeasure_t getMeasure();