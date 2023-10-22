#include "ProductFrequency.cpp"
#include <string>

/**
 *  This will print the menu for the user
*/
void printMenu(void)
{
  std::cout << std::endl;
  std::cout << "===========Products Frequency Menu===========" << std::endl;
  std::cout << "=   1 : Search specific Product Frequency   =" << std::endl;
  std::cout << "=   2 : Print frequency of all products     =" << std::endl;
  std::cout << "=   3 : Print Histgram of products          =" << std::endl;
  std::cout << "=   4 : quit                                =" << std::endl;
  std::cout << "=============================================" << std::endl;
  std::cout << std::endl;
}

/**
 *  This will run the program for the user to query to "./productsInputFile.txt" file
*/
int main(void)
{
  // Location of the file that holds the product data
  std::string fileLocation = "./productsInputFile.txt";

  // declaring variables for user input and file object
  char userInput = 'z';
  std::ifstream fileObject;

  // Open file
  fileObject.open(fileLocation);

  // Create the product frequency object and pass it the file stream
  ProductFrequency allProducts = ProductFrequency(fileObject);

  // Do this while user is not trying to quit
  while(userInput != '4')
  {
    // Print menu for user
    printMenu();

    // Get user input from menu
    std::cin >> userInput;

    // Print depending on user input
    allProducts.printProductFrequncy(userInput);
  }

  // Print the quit message
  std::cout << "Bye" << std::endl;

  return 0;
}
