#include "ProductFrequency.hh"
#include <fstream>
#include <iostream>
#include <fstream>
#include <map>

/**
 * This will create the ProductFrequency object and initialize the map based on the
 * input file contents
 * 
 * @param in std::ifstream& fileName
*/
ProductFrequency::ProductFrequency(std::ifstream& fileName)
{
  // Declare line data
  std::string lineData = "";

  // Loop over file while there are still lines in the file
  while(std::getline(fileName, lineData))
  {
    // Check if the map has the product already in its count
    if(ProductFrequencyMap_.find(lineData) == ProductFrequencyMap_.end())
    {
      // Add product if it does not exist in map
      ProductFrequencyMap_.insert(std::pair<std::string, int>(lineData, 1));
    }
    else
    {
      // Increment the count of the object
      ProductFrequencyMap_.find(lineData)->second+=1;
    }
  }

  // Create the data file
  createDataFile(ProductFrequencyMap_);
}

/**
 *  This will save off the count of products and frequencies to frequency.dat
 * 
 *  @param in std::map<std::string, int> frequencyMap
*/
void ProductFrequency::createDataFile(std::map<std::string, int> frequencyMap)
{
  // Create the output stream
  std::ofstream dataOutputFile;

  // Open the file location
  dataOutputFile.open(ProductFrequency::dataFileLocation_);

  // Loop through map
  for(auto product = ProductFrequencyMap_.begin(); product != ProductFrequencyMap_.end(); ++product)
  {
    // Write line to file
    dataOutputFile << product->first << " " << product->second << std::endl;
  }

  // Close the file
  dataOutputFile.close();
}

/**
 * This will print multiple ways depending on user input
*/
void ProductFrequency::printProductFrequncy(char& outputType)
{
  // Creating for case 1
  std::string productName = "";

  // Switch for all options of printing
  switch(outputType)
  {
    // Prompt user for specific product
    case '1':
      // Print user prompt
      std::cout << std::endl;
      std::cout << "What Product Would you like the frequency for?" << std::endl;

      // Get product name from user
      std::cin >> productName;

      // Check if that product exists
      if(ProductFrequencyMap_.find(productName) != ProductFrequencyMap_.end())
      {
        // Print product name requested and frequency
        std::cout << "Product Name: " << productName << std::endl;
        std::cout << "Product Frequency: " << ProductFrequencyMap_.find(productName)->second << std::endl;
      }
      else
      {
        // Print that the product isn't in map
        std::cout << "Product doesn't exist in file" << std::endl;
      }

      break;
    
    // Printing all products and their frequencies to the screen
    case '2':
      // newline
      std::cout << std::endl;

      // Loop through map
      for(auto product = ProductFrequencyMap_.begin(); product != ProductFrequencyMap_.end(); ++product)
      {
        // Print name and frequency
        std::cout << product->first << " " << product->second << std::endl;
      }

      break;
    
    // Printing the histogram
    case '3':
      // Newline
      std::cout << std::endl;

      // Loop over map
      for(auto product = ProductFrequencyMap_.begin(); product != ProductFrequencyMap_.end(); ++product)
      {
        // Print the name of the product
        std::cout << product->first << " ";
        
        // Loop over frequency amount
        for(int freqCount = 0; freqCount < product->second; ++freqCount)
        {
          // Print '*' for histogram
          std::cout << "*";
        }

        // Newline
        std::cout << std::endl;
      }
      break;

    // User input a value that isn't an option for printing
    default:
      // Print message for invalid input
      std::cout << std::endl;
      std::cout << "Try another input" << std::endl;
      std::cout << std::endl;
      break;
  };
}
