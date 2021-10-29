#include <iostream>

/*
m     n
100   3000 --> false at (8*m + 17*n <= 50000)
1000  1300 --> false at (4*m + n <= 5000)
-25   2000 --> false at (m >= 0)
700   2000 --> true
500   2600 --> false at (5*m + 3*n <= 10000)
1200  100  --> false at (m <= 1100)
1000  -10  --> false at (n >= 0)
*/


int main();

int main(){

    int m{1000};
    int n{-10};

    if (!(5*m + 3*n <= 10000)){
        std::cout << 0;
    }
    else if (!(m <= 1100)){
        std::cout << 1;
    }
    else if (!(4*m + n <= 5000)){
        std::cout << 2;
    }
    else if (!(8*m + 17*n <= 50000)){
        std::cout << 3;
    }
    else if (!(m >= 0)){
        std::cout << 4;
    }
    else if (!(n >= 0)){
        std::cout << 5;
    }
    else{
        std::cout << 6;
    }

    return 0;

}