#ifndef PATHFINDING_PATH_H
#define PATHFINDING_PATH_H

#include <array>
#include <vector>

namespace Path{
    inline constexpr int row_length {9};
    inline constexpr int col_length {9};

    using board_t = std::array<std::array<int, col_length>, row_length>;

    enum State{
        start,
        end,
        blockage,
        clear,
        calculated,
    };

    struct Node{
        int m_row;
        int m_col;
    };

    using path = std::vector<int>;
    void print(const board_t& board);
    board_t make_board();
    path  findPath();
}

#endif //PATHFINDING_PATH_H
