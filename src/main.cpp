#include <iostream>
#include "path.h"

constexpr int blockage = static_cast<int> (Path::State::blockage);
constexpr int clearance = static_cast<int> (Path::State::clearance);

int main(){
    grid_t grid {clearance,clearance, clearance, clearance, blockage, clearance,clearance, clearance, clearance};
    Path::Node start {0, 0, true};
    Path::Node end {2, 2, true};
    path_t paths {Path::findPath(grid, start, end)};

    for(int i = static_cast<int> (paths.size()) - 1; i >= 0; --i){
        std::cout << "Row: " << paths[i].m_row << " Column: " << paths[i].m_col <<  std::endl;
    }

    return 0;
}