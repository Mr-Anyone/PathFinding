#include <iostream>
#include <cmath>
#include <array>
#include "path.h"


int main(){
    Path::board_t board {Path::make_board()};
    Path::print(board);

    return 0;
}