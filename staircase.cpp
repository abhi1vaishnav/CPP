#include <iostream>

int main();

int main() {
  double x{0.0};

  std::cout << "Enter value of x: ";
  std::cin >> x;

  // This local variable should hold the result of stair( x )
  int stair_result{};

  // TASK: write code that calculates an integer value
  // corresponding to the value of the function stair( x ) 214here

  int some_number { };

  if (x >=0){
    //nonnegative numbers
    while (x >= some_number){
      
      stair_result = some_number;

      some_number += 1;

    }
  }
  else {
    int some_neg {};
    //negative numbers
    while (x < some_neg){
      stair_result = some_neg-1;
      
      some_neg--;
    }
  }

  std::cout << "The value of stair(x) is: " << stair_result << std::endl;

 return 0;
}
