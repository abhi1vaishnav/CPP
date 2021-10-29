#include <iostream>

int main();

int main(){

    int n1{};
    int n2{};
    int prime{0};

    std::cout << "Enter first number: ";
    std::cin >> n1;

    std::cout << "Enter second number: ";
    std::cin >> n2;

    bool is_prime{true};
    int prime_numbers{0};

    //if the numbers are two, print out that it is a prime number
    if (n1 == 2 && n2 == 2 ){
        std::cout << "Primes in range: 2";
        prime_numbers ++;
    }
    else if (n1 == 1 && n2 == 2){
        std:: cout << "Primes in range: 2";
    }
    else if (n1 == 1 && n2 == 1){
        std::cout << "No primes in range.";
    }
    else {        
        for (int i{n1}; i <= n2; i++){
            for (int k{2}; k < i; k++){
                if(i%k == 0){
                    is_prime = false;
                }
            }
            if (is_prime && prime == 0){
                std::cout << "Primes in range: ";
                prime ++;
            }
            if (is_prime){
                prime_numbers ++;
                std::cout << i << " ";
            }
            is_prime = true;
        }
    }
    
    if (prime_numbers == 0) {
        std::cout << "\nNo primes in range.";
    }

    return 0;

}