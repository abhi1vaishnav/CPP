#include <iostream>

// Function declarations
int main();

// Function definitions

// int main()
//
// This program queries the user for an integer 'n' and
// then calculates the integer square root of that value.
// The integer square root is the largest integer 'isqrt'
// such that 'isqrt*isqrt <= n'.
//
// Exercises:
//   1. Eliminate the loop variable 'm'.
int main() {
  int n{};
  std::cout << "Enter an integer: ";
  std::cin >> n;

  for ( int isqrt{0}; true; ++isqrt ) {
    if ( isqrt*isqrt > n ) {
      std::cout << "The integer square root of " << n << " is " << (isqrt-1) << std::endl;  
      break;
    }
  }


  return 0;
}