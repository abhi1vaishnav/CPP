#include <iostream>

// Function declarations
int main();

// Function definitions

// int main()
//
// This program queries the user for an integer and
// attempts to find if that integer is the sum of two
// non-zero squares. 
//
// Exercises:
//    1. Rewrite the first part of the function to
//       ensure the user enters an integer that is
//       greater than or equal to 1.
//
//    2. The outer for loop continues running so long
//       as 'm1 < n'.  Suppose 'm1*m1 >= n', is there
//       any point in continuing? Update the condition
//       so that we stop if this condition is satisfied.
//
//    3. The inner for loop continues iterating so long
//       as m2 < n, but suppose '(m1*m1 + m2*m2) > n',
//       is there any point in continuing? Update the
//       conditional statement to have the inner loop
//       end early if ever this condition is satisfied.
int main() {
  int n{};
    std::cout << "Enter an integer: ";
    std::cin >> n;

    while (n <= 0){
        std::cout << "Number must be greater than or equal to 1" << std::endl;
        std::cout << "Enter an integer: ";
        std::cin >> n;
    }

  bool is_found{ false };

  int m1{};
  int m2{};

  for ( m1 = 1; m1 < n; ++m1 ) {
      if ( (m1*m1) >= n){
          break;
      }
    for ( m2 = m1; m2 < n; ++m2 ) {
      if ( (m1*m1 + m2*m2) == n ) {
        is_found = true;
        break;   // exits the inner for loop
      }
      else if ( (m1*m1 + m2*m2) >= n){
          break;
      }
      else if ( (m2*m2) >= n ){
          break;
      }
    }

    if ( is_found ) {
      break;   // exits the outer for loop
    }
  }

  if ( is_found ) {
    std::cout << n << " = " << m1 << "^2 + " << m2 << "^2" << std::endl;
  } else {
    std::cout << n << " is not the sum of two non-zero squares" << std::endl; 
  }

  return 0;
}