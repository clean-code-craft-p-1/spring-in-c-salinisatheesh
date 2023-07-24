#include "stats.h"
#include <numeric>
#include <limits>
#include <algorithm>
using namespace Statistics;
#define Assignment_NAN (std::numeric_limits<double>::quiet_NaN())

Stats Statistics::ComputeStatistics(const std::vector<double>&vecValues) {
	//Implement statistics here
	Stats stat;

	if (!vecValues.empty())
	{
		double sum = accumulate(vecValues.begin(), vecValues.end(), 0.0);
		stat.average = (sum / vecValues.size());

		stat.max = *(std::max_element(vecValues.begin(), vecValues.end()));
		stat.min = *(std::min_element(vecValues.begin(), vecValues.end()));
	}
	else {
		stat.average = Assignment_NAN;
		stat.max = Assignment_NAN;
		stat.min = Assignment_NAN;
	}
			

	return stat;
		
}
