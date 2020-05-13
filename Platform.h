#pragma once


#include <SFML/Graphics.hpp>


class Platform{

    public:
        Platform(int left,int top,int width,int height,sf::Color color){
            //TODO: figure out why this isnt drawing correctly.
            platform.setSize(sf::Vector2f(width,height));
            platform.setPosition(left,top);
            platform.setFillColor(color);
        }

        void draw(sf::RenderWindow &window) {
            window.draw(platform);
        }


    private:
        sf::RectangleShape platform;
        



};
