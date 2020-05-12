//Common C++ libraries
#include <string>
#include <iostream>
#include <sstream>

//SFML libraries
#include <SFML/Graphics.hpp>

//Project header files
#include "Player.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    std::string textureFile = "resources/2x/attack_0.png";

    // Create player object
    Player player(textureFile);

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2 - 445) , (sf::VideoMode::getDesktopMode().height / 2) - 480);
  
    window.create(sf::VideoMode(1000,500), "My Platformer", sf::Style::Titlebar | sf::Style::Close);
  
    window.setPosition(centerWindow);
  
    window.setKeyRepeatEnabled(true);


    //draw background (let's start with white, to see our sprite better)
    //
    sf::RectangleShape background(sf::Vector2f(window.getSize().x,window.getSize().y));
    background.setFillColor(sf::Color::White);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        window.draw(background);
        // Draw the sprite
        //window.draw(sprite);
        
        // Draw the player
        player.draw(window);
        
        // Update the window
        window.display();
    }
    return 0;
}
