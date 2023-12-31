
#include <vector> // Add this line to include the vector header

class IAlerter {
public:
    virtual void alert() = 0;
};

// EmailAlert class 
class EmailAlert : public IAlerter {
public:
    void alert() override;

    bool emailSent = false; 
};

// LEDAlert class 
class LEDAlert : public IAlerter {
public:
    void alert() override;

    bool ledGlows = false; // Flag to indicate whether the LED alert was triggered
};

// StatsAlerter class
class StatsAlerter {
public:
    StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters);

    
    void checkAndAlert(const std::vector<float>& data);

private:
    float maxThreshold; // Maximum threshold to trigger alerts
    std::vector<IAlerter*> alerters; // Vector of IAlerter pointers to trigger alerts
};

