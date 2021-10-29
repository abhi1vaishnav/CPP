#include <iostream>

int main();

int main(){

    double a{};
    double b{};
    double c{};
    double d{};
    double e{};
    double f{};
    double g{};
    double h{};


    std::cout << "Enter the first number in the matrix: ";
    std::cin >> a;

    std::cout << "Enter the second number in the matrix: ";
    std::cin >> b;

    std::cout << "Enter the third number in the matrix: ";
    std::cin >> c;

    std::cout << "Enter the fourth number in the matrix: ";
    std::cin >> d;

    std::cout << "Enter the fifth number in the matrix: ";
    std::cin >> e;

    std::cout << "Enter the sixth number in the matrix: ";
    std::cin >> f;

    std::cout << "Enter the seventh number in the matrix: ";
    std::cin >> g;

    std::cout << "Enter the eighth number in the matrix: ";
    std::cin >> h;

    double m11{(a*e)+(b*g)};
    double m12{(a*f)+(b*h)};
    double m21{(c*e)+(d*g)};
    double m22{(c*f)+(d*h)};
    
    std::cout << "m1,1: " << m11 << std::endl;
    std::cout << "m1,2: " << m12 << std::endl;
    std::cout << "m2,1: " << m21 << std::endl;
    std::cout << "m2,2: " << m22 << std::endl;

    return 0;


}