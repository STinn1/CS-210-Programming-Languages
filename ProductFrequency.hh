#include <string>
#include <istream>
#include <map>

class ProductFrequency
{
  public:
    ProductFrequency(std::ifstream& fileName);

    void printProductFrequncy(char& outputType);

    void createDataFile(std::map<std::string, int> frequencyMap);

  private:
    std::map<std::string, int> ProductFrequencyMap_;

    inline static const std::string dataFileLocation_ = "frequency.dat";
};
