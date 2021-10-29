#include <iostream>
#include <cmath>


//cos( std::sqrt( x ) )
// Function declaration below:
// TODO
//


// Only modify main's definition for your own testing
// Do not touch the preprocessor directives (#ifndef .. #endif)

#ifndef MARMOSET_TESTING
// Do not modify!
int main();
#endif
double find_zero( double initial_value, double step_size );

// Function definition below:
// TODO
//
//
//



#ifndef MARMOSET_TESTING
int main()
{
    // Modify here for testing purposes
    find_zero(65.0,-0.5);
    return 0;
}
#endif

double find_zero( double initial_value, double step_size ){

    double x{initial_value};
    double X{};
    double previous{};

    X = cos( std::sqrt( initial_value ) );


    std::cout << "f(" << initial_value << ") = " << X << std::endl;

    if (X == 0){
        std::cout << "Root found: x = " << x;
        return x;
    }

    for (int i{0}; i < 99; ++i){
        
        x += step_size;

        previous = X;

        X = cos( std::sqrt( x ) );

        std::cout << "f(" << x << ") = " << X << std::endl;

        if (X == 0){
            std::cout << "x found: " << x;
            return x;
        }

        if (X > 0 && previous < 0 || X < 0 && previous > 0){
            step_size = -step_size;
            step_size /= 10;
        }
    }

    std::cout << "Root found: x = " << x;
    return x;


}
