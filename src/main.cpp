#include <SFML/Graphics.hpp>
#include <iostream>
#include "draw.h"
#include "path.h"

struct Node{
    int row;
    int col;
};

Node getNodeFromMousePos(int x, int y){
    return Node {static_cast <int> (y / (Constants::by + Constants::lineWidth)), static_cast <int> (x / (Constants::bx + Constants::lineWidth))};
}

int main(){
    std::cout << "Built system worked" << std::endl;
    grid_t grid {makeGrid()};
    sf::RenderWindow window(sf::VideoMode(Constants::video_width, Constants::video_height), "Path Finding");
//    window.setFramerateLimit(60); // call it once, after creating the window

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
             switch(event.type){
                 case sf::Event::Closed:
                     window.close();
                     break;
             }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ // Left click to add blockage
                sf::Vector2i position = sf::Mouse::getPosition(window);
                auto gridPos = getNodeFromMousePos(position.x, position.y);
                grid[gridPos.row][gridPos.col] = Path::State::blockage;
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                sf::Vector2i position = sf::Mouse::getPosition(window);
                auto gridPos = getNodeFromMousePos(position.x, position.y);
                grid[gridPos.row][gridPos.col] = Path::State::clearance;
            }
        }

        window.clear(sf::Color::Black);
        drawGrid(window);
        drawNodes(window, grid);
        window.display();
    }


    return 0;
}