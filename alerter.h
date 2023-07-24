#include <stdio.h>
#include <vector>
#include <cmath>

class IAlerter {
public:
    virtual void alert() = 0;
};

class EmailAlert : public IAlerter {
public:
    void alert() override;
    bool emailSent = false;
};

class LEDAlert : public IAlerter {
public:
    void alert() override;
    bool ledGlows = false;
};

class StatsAlerter {
public:
    StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters);
    void checkAndAlert(const std::vector<float>& numberset);

private:
    float maxThreshold_;
    std::vector<IAlerter*> alerters_;
};


