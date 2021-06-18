#include <SFML/Window.hpp>
#include "path.h"
#include <iostream>


constexpr int video_with {800};
constexpr int video_height {600};

int main(){
    std::cout << "Built system worked" << std::endl;
    sf::Window window(sf::VideoMode(video_with, video_height), "Path Finding");

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }


    return 0;
}