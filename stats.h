
#include <vector>
namespace Statistics 
{
    
    // define the Stats structure here. See the tests to infer its properties
    struct Stats
    {
        float min{};
        float max{};
        float average{};

    };
    
    Stats ComputeStatistics(const std::vector<float>& values );

}
