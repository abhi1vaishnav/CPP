#include <iostream>
int main();

int main() {
    int m{};
    int n{};

    std::cout << "Enter the first integer: ";
    std::cin >> m;

    while (m <= 0){
        std::cout << "Integer value must be positive" << std::endl;
        std::cout << "Enter the first integer: ";
        std::cin >> m;
    }

    std::cout << "Enter a second integer: ";
    std::cin >> n;

    while (n <= 0){
        std::cout << "Integer value must be positive" << std::endl;
        std::cout << "Enter a second integer: ";
        std::cin >> n;
    }
    // Make sure m >= n
    if ( m < n ) {
        int tmp{m};
        m = n;
        n = tmp;
    }
    // Perform our gcd algorithm
    while ( m%n != 0 ) {
        int rem{m%n};
        m = n;
        n = rem;
    }
    std::cout << "The gcd is " << n << std::endl;
    return 0;
}