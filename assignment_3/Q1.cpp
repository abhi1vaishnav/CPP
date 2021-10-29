#include <iostream>

#inculde <cmath> 


bool main();
bool done_assignment( int assignment_number1 );
bool done_assignment( int assignment_number2 );


bool done_assignment( int assignment_number1 ) {
    return true;
}


bool done_assignment( int assignment_number2 ) {
    return true;
}


bool main() {
    done_assignment((2));

    return 0;
}

//All errors: 
//main function should be of type int
//cannot have 2 functions with the same name and perameters
//include is spelled incorrectly when importing the cmath library
