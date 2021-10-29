#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif
unsigned int add_checksum(unsigned int n);
void add_checksum( unsigned int array[], std::size_t capacity );
bool verify_checksum( unsigned int n );
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );

#ifndef MARMOSET_TESTING
int main() {


	unsigned int value_to_protect{28};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
    if (verify_checksum(protected_value)){
        std::cout << "The checksum is valid." << std::endl;
    }
    else  {
        std::cout << "The checksum is invalid." << std::endl;
    }

    const std::size_t QTY_VALUES {3};
    unsigned int value_series[QTY_VALUES] {5529228};
    add_checksum(value_series, QTY_VALUES);
    
    std::cout << std::endl;
    return 0;
}
#endif


unsigned int add_checksum(unsigned int n){

    unsigned int temp{n};
    unsigned int temp3{n};

    if (n <= 99999999){
        
        int length{};

        //get the number of digits in the integer
        while (n != 0){
            n /= 10;
            length ++;
        }

        int digits[length];

        for (int k{0}; temp3 != 0; ++k){
            digits[k] = temp3%10;
            temp3 /= 10;
        }

        // next step in checksum is to multiply every other element by two
        if (length %2 != 0){
            for (int k{length - 1}; k >= 0; k -= 2){
                digits[k] *= 2;
                if (digits[k] > 9){
                    int sum{0};
                    while ( digits[k] != 0){
                        sum += digits[k]%10;
                        digits[k] /= 10;
                    }
                    digits[k] = sum;
                    sum = 0;
                }
            }
        }
        else {
            for (int k{length - 1}; k >= 0; k -= 2){
                digits[k-1] *= 2;
                if (digits[k-1] > 9){
                    int sum{0};
                    while ( digits[k-1] != 0){
                        sum += digits[k-1]%10;
                        digits[k-1] /= 10;
                    }
                    digits[k-1] = sum;
                    sum = 0;
                }
            }
        }
        

        int addition{0};
        //add all the elements in the array
        for (int k{0}; k < length; ++k){
            addition += digits[k];
        }


        addition *= 9;

        return (temp*10+addition%10);
    }
    return UINT_MAX;

} //end of funtion

void add_checksum( unsigned int array[], std::size_t capacity ){

    for (int i{0}; i < capacity; ++i){
        array[i] = add_checksum(array[i]);
    }

} //end of function

bool verify_checksum( unsigned int n ){

    unsigned int temp{n};
    
    //get the first eight digits of the checksum number
    temp = (temp - (temp % 10))/10;

    int num = add_checksum(temp);


    return ((n == num) && (n <= 999999999));

}//end of function

unsigned int remove_checksum( unsigned int n ){

    if (verify_checksum(n)){
        return (n - (n % 10))/10;
    }
    return UINT_MAX;

}//end of function

void remove_checksum( unsigned int array[], std::size_t capacity ){

    for (int i{0}; i < capacity; ++i){

        if (verify_checksum(array[i])){
            array[i] = (array[i] - (array[i] % 10))/10;
        }
        else {
            array[i] = UINT_MAX;
        }

    }

}