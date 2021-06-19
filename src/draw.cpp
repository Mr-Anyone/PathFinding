#include "draw.h"
#include "path.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void drawGrid(sf::RenderWindow& window){
    float dx {static_cast<float> (Constants::video_width) / Path::column_length};
    float dy {static_cast<float> (Constants::video_height) / Path::row_length};

    for(int i = 0; i<Path::column_length ; ++i){ // Vertical Line
        sf::RectangleShape line (sf::Vector2f (Constants::lineWidth, Constants::video_height));
        line.setPosition(static_cast<float> (i) * dx, 0.f);
        window.draw(line);
    }

    for(int i = 0; i<Path::row_length ; ++i){ // Horizontal Line
        sf::RectangleShape line (sf::Vector2f (Constants::video_width, Constants::lineWidth));
        line.setPosition(0.f, static_cast<float> (i) * dy);
        window.draw(line);
    }
}

static void drawNode(sf::RenderWindow& window, const sf::Color& color, int x, int y){
    sf::RectangleShape rectangle (sf::Vector2f (Constants::bx, Constants::by));
    rectangle.setFillColor(color);
    rectangle.setPosition(Constants::bx * x + Constants::lineWidth * x + Constants::lineWidth, Constants::by * y + Constants::lineWidth * y + Constants::lineWidth);

    window.draw(rectangle);
}

void drawNodes(sf::RenderWindow& window, const grid_t& grid){
    for(int i = 0; i<grid.size(); ++i)
    {
        for(int x = 0; x<grid[i].size(); ++x)
        {
            switch(grid[i][x]){
                case Path::State::clearance:
                    drawNode(window, sf::Color::Red, x, i);
                    break;
                case Path::State::blockage:
                    drawNode(window, sf::Color::White, x, i);
                    break;
            }

        }
    }
}

void draw_path(sf::RenderWindow& window, const path_t& path){
    for(auto& ele: path){
        drawNode(window, sf::Color::Green, ele.m_row, ele.m_col);
    }
}