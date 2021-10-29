#include <iostream>
int main();
int main() {

    int n{};
    std::cout << "Enter a positive integer to be factored: ";
    std::cin >> n;

    while (n < 2){
        std::cout << "Enter an integer greater than or equal to 2" << std::endl;
        std::cout << "\nEnter a positive integer to be factored: ";
        std::cin >> n;
    }

    int possible_factor{2};
    bool first{true};
    int num{0};

    while ( n > 1 ) {
        while ( n%possible_factor == 0 ) {
            n /= possible_factor;
            num ++;
        }
        if (!first && num > 0){
            std::cout << " * " << possible_factor << "^" << num;
        }
        else if (num > 0){
            std::cout << possible_factor << "^" << num;
            first = false;
        }
        num = 0;
        ++possible_factor;
    }
    std::cout << std::endl;

    return 0;
}