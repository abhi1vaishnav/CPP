#include <iostream>
#include <cassert>

int main();
int quadrant( double x, double y );

int main(){

    int x{};
    int y{};

    std::cout << "Enter the x co-ordinate: ";
    std::cin >> x;

    std::cout << "Enter the y co-ordinate: ";
    std::cin >> y;

    quadrant(x, y);
}



int quadrant( double x, double y ) {
    if ( (x == 0)|| (y == 0)) {
        return 0;
    } 
    else if ( x > 0 ) {
        if ( y > 0 ) {
            assert( x > 0 && y > 0 );
            return 1;
        } 
        else {
            assert( x > 0 && y < 0 );
            return 4;
        }
    } 
    else {
        if ( y > 0 ) {
            assert( x < 0 && y > 0 );
            return 2;
        }
        else {
            assert( x < 0 && y < 0 );
            return 3;
        }
    }
}