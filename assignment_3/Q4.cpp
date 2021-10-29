#include <iostream>
#include <cassert>

int main();
void flip_four_digit_integer(int n);

int main(){

    int n{};

    std::cout << "Enter a four digit integer: " << std::endl;
    std::cin >> n;

    flip_four_digit_integer(n);

    return 0;
}

void flip_four_digit_integer(int n){

    //positive numbers
    if (n > 0){
        while (n != 0){
            std::cout << n%10;
            n /= 10;
        }
    }
    //negative numbers
    else {
        n = -n;
        std::cout << "-";
        while (n != 0){
            std::cout << n%10;
            n /= 10;
        }   
    }
}
