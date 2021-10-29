#include <iostream>

int main();
void print_complex(double a, double b);

int main(){

    print_complex(9, 8);

    return 0;
}

void print_complex(double a, double b){

    if (b > 0){
        std::cout << a << " + " << b << "j";
    }
    else if ( b == 0 ){
        std::cout << a;
    }
    else{
        b = -b;
        std::cout << a << " - " << b << "j"; 
    }

}