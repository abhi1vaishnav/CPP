#include <iostream>
#include <cmath>

int main();
void print_complex(double a, double b);
void print_roots(double a, double b, double c);

int main(){

    print_roots(1, 0, 25);

    return 0;
}

void print_complex(double a, double b){

    if (b > 0){
        std::cout << a << " + " << b << "j" << std::endl;
    }
    else if ( b == 0 ){
        std::cout << a;
    }
    else{
        b = -b;
        std::cout << a << " - " << b << "j" << std::endl; 
    }

}

void print_roots(double a, double b, double c){

    double pos_root{};
    double neg_root{};
    double discriminant{(b*b)-(4*a*c)};

    if (discriminant < 0){
        discriminant *= -1;
        print_complex( (b*-1)/(2*a) , sqrt(discriminant)/(2*a));
        print_complex( (b*-1)/(2*a) , (sqrt(discriminant)/(2*a)*-1));
    }
    else if (discriminant == 0){
        std::cout << (b*-1)/(2*a);
    }
    else {
        pos_root = (b*-1)/(2*a) + sqrt(discriminant)/(2*a);
        neg_root = (b*-1)/(2*a) - sqrt(discriminant)/(2*a);
        std::cout << "First Root: " << pos_root << std::endl;
        std::cout << "Second Root: " << neg_root << std::endl;
    }

}

/*

Test Case: x^2 + 25 = 0
Output: 5j, -5j

*/