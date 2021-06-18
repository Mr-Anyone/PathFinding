#include <iostream>
#include "path.h"

int main(){
    grid_t grid {};
    Path::Node start {0, 0, true};
    Path::Node end {5, 5, true};
    path_t paths {Path::findPath(grid, start, end)};

    for(int i = static_cast<int> (paths.size()) - 1; i >= 0; --i){
        std::cout << "Row: " << paths[i].m_row << " Column: " << paths[i].m_col <<  std::endl;
    }

    return 0;
}