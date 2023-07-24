#include <stdio.h>
#include <vector>
#include <cmath>
class StatsAlerter {
public:
    StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters);
    void checkAndAlert(const std::vector<float>& numberset);

private:
    float maxThreshold_;
    std::vector<IAlerter*> alerters_;
};
