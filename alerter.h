#ifndef ALERTER_H
#define ALERTER_H

#include <vector> // Add this line to include the vector header

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

#endif // ALERTER_H

