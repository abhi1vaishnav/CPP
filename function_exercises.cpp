#include <iostream>
#include <string>

/*
int main();
int get_value_no_less_than(std::string, int lower_bound);

int main(){

    //input the number into the lower bound function
    std::cout << get_value_no_less_than("Enter a number: ", 24) << std::endl;

}


int get_value_no_less_than(std::string text, int lower_bound){

    int num{};

    std::cout << text;
    std::cin >> num;
    
    while (num < lower_bound){
        std::cout << "Number was not greater than the lower bound\nPlease try again!\n" << std::endl;
        std::cout << text;
        std::cin >> num;
    }

    return num;
    

} */
/*
int main();
int running_average();


int main(){

 std::cout << running_average() << std::endl;

}

int running_average(){

    double count{0};
    double sum{0};


    while (true){

        int num{};
        std::cout << "Enter a number: ";
        std::cin >> num;
        
        sum += num;
        count ++;


        if (num == 0){
            return sum/count;
        }
        else{
            std::cout << "The average is " << sum/count << std::endl;
        }

    }

} */


int main();
bool is_prime( int n );

int main(){

    int num{};
    std::cout << "Enter a number to check if it's prime: ";
    std::cin >> num;

    std::cout << is_prime(num) << std::endl;
}

bool is_prime (int n){

    if (n < 2){
        return 0;
    }
    if (n == 2){
        return true;
    }
    
    for (int k{3}; k < n; ++k){

        if (n%k == 0){
            return false;
        }
    }

    return true;

}