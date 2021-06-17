#include <iostream>
#include <cstddef>
#include "path.h"



void Path::print(const board_t& board){
    for(std::size_t row {0}; row < board.size(); ++row){ // Row for the board
        for(std::size_t col{0}; col < board[row].size(); ++col){ // The column of the board
            switch(board[row][col]){ // Checking the Board Type
                case State::blockage: 
                    std::cout << "|";
                    break;
                case State::clear:
                    std::cout << "*";
                    break;
                case State::end:
                    std::cout << "E";
                    break;
                case State::start:
                    std::cout << "S";
                    break;
                case State::calculated:
                    std::cout << "C";
                    break;
            }
        }
        
        std::cout << "\n";
    }
}

Path::board_t Path::make_board(){
    Path::Node start {0, 0}; 
    Path::Node end {8,8};
    Path::board_t result;
    
    for(std::size_t row{0}; row<Path::row_length; ++row){
        for(std::size_t col{0}; col < Path::col_length; ++col){

            if(row == start.m_row && col == start.m_col)
                result[row][col] = Path::State::start;
            else if(row == end.m_row && col ==  end.m_col)
                result[row][col] = Path::State::end;
            else
                result[row][col] = Path::State::clear;

        }
    }
    
    return result;
}