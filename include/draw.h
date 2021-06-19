#ifndef PATHFINDING_DRAW_H
#define PATHFINDING_DRAW_H

#include <sfml/Graphics.hpp>
#include "path.h"

namespace Constants{
    inline const sf::Color grey (49, 55, 58);

    inline constexpr int lineWidth {2};

    constexpr int video_width {1920};
    constexpr int video_height {1080};

    constexpr float bx {(video_width -   lineWidth * Path::column_length) / static_cast<float> (Path::column_length)};
    constexpr float by {(video_height - lineWidth * Path::row_length) / static_cast<float> (Path::row_length)};
}

void drawGrid(sf::RenderWindow& window);
void drawNodes(sf::RenderWindow& window, const grid_t& grid);
void draw_path(sf::RenderWindow& window, const path_t& path);
#endif //PATHFINDING_DRAW_H
