#include <iostream>
#include <ctype.h>

int main();

int main(){

    char ch{};

    std::cout << "Enter a character: ";
    std::cin >> ch;

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        std::cout << "This character is a vowel." << std::endl;
    }
    else if (isdigit(ch)){
        std::cout << "The character is a digit" << std::endl;
    }
    else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')'){
        std::cout << "The character is a symbol" << std::endl;
    }
    else {
        std::cout << "The character is a consonant" << std::endl;
    }


    return 0;
}