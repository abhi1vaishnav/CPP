#include <iostream>
#include <bits/stdc++.h>

int main();
double mean(double a, double b, double c, double d);
double median(double a, double b, double c, double d);
double max(double a, double b);
double min(double a, double b);


int main(){

    std::cout << "Mean: " << mean(67, -45, 0, -89) << std::endl;
    std::cout << "Median: " << median(67, -45, 0, -89) << std::endl;

}

double mean(double a, double b, double c, double d){

    return (a+b+c+d)/4;

}

double median(double a, double b, double c, double d){

    double high = max(a, max(b, max(c, d)));

    double low = min(a, min(b, min(c, d)));

    return ((a+b+c+d-low-high)/2);

}

double max( double a, double b ){

    if (a >= b){
        return a;
    }
    else {
        return b;
    }
}

double min( double a, double b ){

    if (a <= b){
        return a;
    }
    else {
        return b;
    }
}


/*
Input:

a = 67
b = -45
c = 0
d = -89

Output: 

Mean: -16.75
Meidan: -22.5

*/