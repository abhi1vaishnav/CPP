#include <iostream>

int main();

int main(){

    double n1{};
    double n2{};
    double n3{};
    double n4{};

    std::cout << "Enter the first num: ";
    std::cin >> n1;

    std::cout << "Enter the second num: ";
    std::cin >> n2;

    std::cout << "Enter the third num: ";
    std::cin >> n3;

    std::cout << "Enter the fourth num: ";
    std::cin >> n4;

    double max{};
    double min{};

    if (n1 >= n2 >= n3 >= n4){
        max = n1;
        min = n4;
    }
    else if (n1 >= n2 >= n4 >= n3){
        max = n1;
        min = n3;
    }
    else if (n1 >= n3 >= n2 >= n4){
        max = n1;
        min = n4;
    }
    else if (n1 >= n3 >= n4 >= n2){
        max = n1;
        min = n2;
    }
    else if (n1 >= n4 >= n2 >= n3){
        max = n1;
        min = n3;
    }
    else if (n1 >= n4 >= n3 >= n2){
        max = n1;
        min = n2;
    }
    else if (n2 >= n1 >= n3 >= n4){
        max = n2;
        min = n4;
    }
    else if (n2 >= n1 >= n4 >= n3){
        max = n2;
        min = n3;
    }
    else if (n2 >= n3 >= n1 >= n4){
        max = n2;
        min = n4;
    }
    else if (n2 >= n3 >= n4 >= n1){
        max = n2;
        min = n1;
    }
    else if (n2 >= n4 >= n1 >= n3){
        max = n2;
        min = n3;
    }
    else if (n2 >= n4 >= n3 >= n1){
        max = n2;
        min = n1;
    }
    else if (n3 >= n1 >= n2 >= n4){
        max = n3;
        min = n4;
    }
    else if (n3 >= n1 >= n4 >= n2){
        max = n3;
        min = n2;
    }
    else if (n3 >= n2 >= n1 >= n4){
        max = n3;
        min = n4;
    }
    else if (n3 >= n2 >= n4 >= n1){
        max = n3;
        min = n1;
    }
    else if (n3 >= n4 >= n1 >= n2){
        max = n3;
        min = n2;
    }
    else if (n3 >= n4 >= n2 >= n1){
        max = n3;
        min = n1;
    }
    else if (n4 >= n1 >= n2 >= n3){
        max = n4;
        min = n3;
    }
    else if (n4 >= n1 >= n3 >= n2){
        max = n4;
        min = n2;
    }
    else if (n4 >= n2 >= n1 >= n3){
        max = n4;
        min = n3;
    }
    else if (n4 >= n2 >= n3 >= n1){
        max = n4;
        min = n1;
    }
    else if (n4 >= n3 >= n1 >= n2){
        max = n4;
        min = n2;
    }
    else if (n4 >= n3 >= n2 >= n1){
        max = n4;
        min = n1;
    }

    std::cout << "\nMaximum: " << max << std::endl;
    std::cout << "\nMinimum: " << min << std::endl;

    return 0;
}