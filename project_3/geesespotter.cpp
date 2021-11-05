#include <iostream>

#include "geesespotter_lib.h"

#include "geesespotter.h"

int cartesian_to_index(int x_value, int y_value, std::size_t xdim, std::size_t ydim);
void index_to_cartesian (std::size_t index_value, std::size_t xdim, std::size_t ydim, int &x_value, int &y_value);


/*
int main(){

    char *p_m{createBoard(5, 5)};
    
    hideBoard(p_m, 5, 5);
    computeNeighbors(p_m, 5, 5);
    reveal(p_m, 5, 5, 0, 2);
    printBoard(p_m, 5, 5);

    return 0;

}
*/

//allocate a char array with xdim * ydim elements and initialize each element with zero.
char *createBoard(std::size_t xdim, std::size_t ydim){
    
    char * array = new char [xdim*ydim] {0};

    return array;

}

//hide all the field values by using the or operator
void hideBoard(char *board, std::size_t xdim, std::size_t ydim){
    
    std::size_t hidden_mask{0x20};

    for (std::size_t i{0}; i < xdim*ydim; ++i){
        *(board+i) |= hidden_mask;
    }

}


void cleanBoard(char *board){
    delete[] board;
    board = nullptr;

}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){
    
    //print the elements of the board
    for (std::size_t i{0}; i < xdim*ydim; ++i){

        if (((*(board+i) >> 4) == 3) || ((*(board+i) >> 4) == 1)){
            std::cout << "M";
        }
        else if ((*(board+i) >> 4) == 2){
            std::cout << "*";
        }
        else{
            std::cout << (int)*(board+i);
        }
        //print on a new line if an entire row has been printed
        if (!((i+1)%xdim)){
            std::cout << std::endl;
        }

    }
}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc){

    std::size_t mark_mask{0x10};

    if ((*(board + ( yloc*xdim ) + xloc) >> 4) == 0){
        return 2;
    }
    *(board + ( yloc*xdim ) + xloc) ^= mark_mask;

    return 0;

}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim) {

    std::size_t last_bit_mask{0xf};

    for (std::size_t i{0}; i < (xdim*ydim); i++){
    
        if ((*(board + i) & last_bit_mask) != 9){

            int xloc{0}, yloc{0};

            std::size_t count{0};

            index_to_cartesian(i, xdim, ydim, xloc, yloc);

            //check if there is a goose at the top left corner
            if ((xloc-1 >= 0) && (yloc-1 >= 0)){
                if ((board [cartesian_to_index(xloc-1, yloc-1, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
            }

            //check if there is a goose to the left
            if (xloc-1 >= 0){
                if ((board [cartesian_to_index(xloc-1, yloc, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
            }

            //check if there is a goose at the bottom left corner
            if ((xloc-1 >= 0) && (yloc+1 < ydim)){
                if ((board [cartesian_to_index(xloc-1, yloc+1, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }  
            }

            //check if there is a goose directly below
            if (yloc+1 < ydim){
                if ((board [cartesian_to_index(xloc, yloc+1, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
           }

            //check if there is a goose at the bottom right corner
            if ((xloc+1 < xdim) && (yloc+1 < ydim)){
                if ((board [cartesian_to_index(xloc+1, yloc+1, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
                
            }

            //check if there is a goose to the right
            if (xloc+1 < xdim){
                if ((board [cartesian_to_index(xloc+1, yloc, xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
            }

            //check if there is a goose at the top right corner
            if ((xloc+1 < xdim) && (yloc-1 >= 0)){
                if ((board [cartesian_to_index((xloc+1), (yloc-1), xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
            }

            //check if there is a goose directly above the concerned field
            if (yloc-1 >= 0){
                if ((board [cartesian_to_index(xloc, (yloc-1), xdim, ydim)] & last_bit_mask) == 9){
                    count ++;
                }
               
            }

            //add the number of geese to the field
            *(board + i) += count;
        }
    }

}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc) {
    
    char *p_r {board + ( yloc*xdim ) + xloc};
    int last_bit_mask{0xf};

    int temp = xloc;

    xloc -= xloc;
    yloc -= yloc;

    (int)(xloc);
    (int)(yloc);

    //if board is already marked, return 1
    if ((*p_r >> 4) == 1 || (*p_r >> 4) == 3){
        return 1;
    }
    //if the field is already revealed return 2
    else if ((*p_r >> 4) == 0){
        return 2;
    }
    //if the field is hidden, reveal it
    //return 9 if the field is a goose
    else if ((*p_r & last_bit_mask) == 9) {
        *p_r &= last_bit_mask; 
        return 9;
    }
    //reveal the value if the field is not a zero
    else if ((*p_r & last_bit_mask) != 0){
        *p_r &= last_bit_mask;
        return 0;
    }
    
    (p_r [cartesian_to_index(xloc, yloc, xdim, ydim)]) &= last_bit_mask;


    xloc += temp;
    if (xloc != 0 && xloc != xdim-1){

        xloc -= xloc;
        //reveal the field at the top left corner if it exists
        if ((xloc-1 >= 0) && (yloc-1 >= 0)){
            (p_r [cartesian_to_index(xloc-1, yloc-1, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field to the left if it exists
        if (xloc-1 >= 0){
            (p_r [cartesian_to_index(xloc-1, yloc, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field at the bottom left corner if it exists
        if ((xloc-1 >= 0) && (yloc+1 < ydim)){
            (p_r [cartesian_to_index(xloc-1, yloc+1, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field below if it exists
        if (yloc+1 < ydim){
            (p_r [cartesian_to_index(xloc, yloc+1, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field at the bottom right corner if it exists
        if ((xloc+1 < xdim) && (yloc+1 < ydim)){
            (p_r [cartesian_to_index(xloc+1, yloc+1, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field to the right if it exists
        if (xloc+1 < xdim){
            (p_r [cartesian_to_index(xloc+1, yloc, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field at the top right corner if it exists
        if ((xloc+1 < xdim) && (yloc-1 >= 0)){
            (p_r [cartesian_to_index(xloc+1, yloc-1, xdim, ydim)]) &= last_bit_mask;
        }

        //reveal the field above if it exists
        if (yloc-1 >= 0){
            (p_r [cartesian_to_index(xloc, yloc-1, xdim, ydim)]) &= last_bit_mask;
        }

        int hidden_mask{0x20};
        xloc += temp;

        if (xloc == 0){
            xloc = xdim-1;
            yloc = 0;
            for (std::size_t i{0}; i < ydim; i ++){
                *(p_r + cartesian_to_index(xloc, yloc+i, xdim, ydim)) |= hidden_mask;
            }
        }
        else if (xloc == (xdim-1)){
            xloc = 0;
            yloc = 0;
            for (std::size_t i{0}; i < ydim; i ++){
                *(p_r + cartesian_to_index(xloc, yloc+i, xdim, ydim)) |= hidden_mask;
            }
        }
    }


    else if ((xloc == 0 && yloc != 0) || (xloc == 0 && yloc != ydim-1)){

        xloc -= xloc;

        (p_r [cartesian_to_index(xloc, yloc-1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc+1, yloc-1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc+1, yloc, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc+1, yloc+1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc, yloc+1, xdim, ydim)]) &= last_bit_mask;        

    }

    else if ((xloc == xdim-1 && yloc != 0) || (xloc == xdim-1 && yloc != ydim-1)){

        xloc -= xloc;

        (p_r [cartesian_to_index(xloc, yloc-1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc, yloc+1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc-1, yloc+1, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc-1, yloc, xdim, ydim)]) &= last_bit_mask;
        (p_r [cartesian_to_index(xloc-1, yloc-1, xdim, ydim)]) &= last_bit_mask;

    }

    return 0;

}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim) {

    bool game{true};
    int last_bit_mask{0xf};


    for (std::size_t i{0}; i < xdim*ydim; ++i){
        if (((board [i]) & last_bit_mask) != 9){
            if (((board [i]) >> 4) != 0){
                //if the field is not a goose and has not been revealed, return false
                return false;
            }
        }
    }
    

    return game;

}

//function to convert from index to cartesian coordinates using pass by reference as parameters
void index_to_cartesian (std::size_t index_value, std::size_t xdim, std::size_t ydim, int &x_value, int &y_value){
    
    x_value = index_value%xdim;
    y_value = index_value/xdim;

}

int cartesian_to_index(int x_value, int y_value, std::size_t xdim, std::size_t ydim){

    //return index value
    return (x_value + (y_value*xdim));
}