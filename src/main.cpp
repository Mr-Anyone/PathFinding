#include <SFML/Graphics.hpp>
#include <iostream>
#include "draw.h"
#include "path.h"

struct Node {
    int row;
    int col;
};

Node getNodeFromMousePos( sf::RenderWindow& window) {
    sf::Vector2i position = sf::Mouse::getPosition(window);

    return Node{static_cast <int> (position.y / (Constants::by + Constants::lineWidth)),
                static_cast <int> (position.x / (Constants::bx + Constants::lineWidth))};
}

void clear(path_t& path, grid_t& grid){
    grid = makeGrid();
    path.clear();
}

int main() {
    std::cout << "Built system worked" << std::endl;
    grid_t grid{makeGrid()};
    sf::RenderWindow window(sf::VideoMode(Constants::video_width, Constants::video_height), "Path Finding");
    window.setFramerateLimit(60); // call it once, after creating the window

    path_t path{};
    Path::Node startNode{0, 0, true};
    Path::Node endNode{0, 0, true};
    Node gridPos;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::C: // Clear Input
                            clear(path, grid);
                            break;

                        case sf::Keyboard::Enter: // Solve
                            path = Path::findPath(grid, startNode, endNode);
                            break;

                        case sf::Keyboard::S: // Start Node
                            gridPos = getNodeFromMousePos(window);
                            startNode.m_row = gridPos.row;
                            startNode.m_col = gridPos.col;
                            grid[gridPos.row][gridPos.col] = Path::State::startnode;
                            break;

                        case sf::Keyboard::E: // End Node
                            gridPos = getNodeFromMousePos(window);
                            endNode.m_row = gridPos.row;
                            endNode.m_col = gridPos.col;
                            grid[gridPos.row][gridPos.col] = Path::State::endnode;
                            break;

                    }

                    break;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Left click to add blockage
                gridPos = getNodeFromMousePos(window);
                grid[gridPos.row][gridPos.col] = Path::State::blockage;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                gridPos = getNodeFromMousePos(window);
                grid[gridPos.row][gridPos.col] = Path::State::clearance;
            }
        }

        window.clear(sf::Color::Black);
        drawGrid(window);
        drawNodes(window, grid);
        draw_path(window, path);
        window.display();
    }


    return 0;
}