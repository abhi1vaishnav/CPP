#include <iostream>

void output_velocity_and_acceleration(double position_measurements[],std::size_t qty_measurements);

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main(){

    double array [5] = {1.4, 1.6, 1.7, 1.8, 1.8};

    output_velocity_and_acceleration(array, 5);

    return 0;
}
#endif

void output_velocity_and_acceleration(double position_measurements[],std::size_t qty_measurements){

    if (qty_measurements == 0 || qty_measurements == 1){
        std::cout << "Insufficient measurements for velocity calculation. \nInsufficuent measurements for acceleration calculation.";
    }
    else if (qty_measurements == 2){
        std::cout << "Velocity calculations [m/s]: \n" << (position_measurements[1] - position_measurements[0]) << std::endl;
        std::cout << "Insufficient measurements for acceleration calculation." << std::endl;
    }
    else{
        double vel[qty_measurements-1];
        double acc[qty_measurements-2];

        for (std::size_t i{0}; i < (qty_measurements-1); i ++){
            vel[i] = 0;
        }

        for (std::size_t k{0}; k < (qty_measurements-2); k ++){
            acc[k] = 0;
        }

        for (std::size_t i{0}; i < (qty_measurements-1); i ++){
            vel[i] = position_measurements[i+1] - position_measurements[i];
        }

        for (std::size_t k{0}; k < (qty_measurements-2); k ++){
            acc[k] = vel[k+1] - vel[k];
        }
        

        std::cout << "Velcoity calculations [m/s]:" << std::endl;
        for (std::size_t i{0}; i < (qty_measurements-1); i ++){
            std::cout << vel[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Acceleration calculations [m/s^2]:" << std::endl;
        for (std::size_t k{0}; k < (qty_measurements-2); k ++){
            std::cout << acc[k] << " ";
        }
        std::cout << std::endl;
    }

}