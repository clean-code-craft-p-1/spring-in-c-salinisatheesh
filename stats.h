#include <vector>

namespace Statistics {
	// define the Stats structure here. See the tests to infer its properties
	struct Stats {
		double average;
		double max;
		double min;


	}; 
	
	Stats ComputeStatistics(const std::vector<double>& vecValues);
}

 class IAlerter {

	 virtual void Alert() = 0;
};
class EmailAlert : public IAlerter {
public:
	bool emailSent = true;

	void Alert();
};

class LEDAlert : public IAlerter {
public:
	void Alert();
	bool ledGlows = true;
};

class StatsAlerter {

public:
	float maxThreshold;
	StatsAlerter(const float maxThreshold, std::vector<IAlerter*> vecAlert);
	void checkAndAlert(const std::vector<double>& vecValues);
};