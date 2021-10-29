#include <iostream>

// Function declarations
int main();

// Function definitions
int main() {
  int k{};
  
  for ( k = 0; k < 20; ++k ) {
    std::cout << "k = " << k << std::endl;

    int value{};
    std::cout << "Add what to 'k'? ";
    std::cin >> value;

    k += value;

    std::cout << "The value of k is now k = " << k << std::endl << std::endl;
  }

  std::cout << "The final value of 'k' is " << k << std::endl;

  return 0;
}