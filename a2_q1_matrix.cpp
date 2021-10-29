#include <iostream>

int main();

int main(){

    double num1{};
    double num2{};
    double num3{};
    double num4{};

    std::cout << "Enter the first number in the matrix: ";
    std::cin >> num1;

    std::cout << "Enter the second number in the matrix: ";
    std::cin >> num2;

    std::cout << "Enter the third number in the matrix: ";
    std::cin >> num3;

    std::cout << "Enter the fourth number in the matrix: ";
    std::cin >> num4;

    double determinant{(num1*num4)-(num2*num3)};
    
    if (determinant == 0){
        std::cout << "\nThe matrix is not invertible" << std::endl;
    }
    else {
        std::cout << "\nThe matrix is " << determinant << std::endl;
    }

    return 0;

}