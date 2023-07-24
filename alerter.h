#ifndef ALERTER_H
#define ALERTER_H

class IAlerter {
public:
    virtual ~IAlerter() {}
    virtual void Alert() = 0;
};

class EmailAlert : public IAlerter {
public:
    bool emailSent = false;
    void Alert() override;
};

class LEDAlert : public IAlerter {
public:
    bool ledGlows = false;
    void Alert() override;
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
