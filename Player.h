#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GameObject.h"
 
class Player {
public:
    /*
    Player(sf::Vector2f size) {
        player.setSize(size);
        player.setFillColor(sf::Color::Green);
    }
    */

    Player(std::string fileName){
        
        if (!texture.loadFromFile("resources/2x/attack_0.png")) return EXIT_FAILURE;
        sprite.setTexture(texture);

    }
  
    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
  
    void move(sf::Vector2f distance) {
        player.move(distance);
    }
  
    void setPos(sf::Vector2f newPos) {
        sprite.setPosition(newPos);
    }

    void setPos(float x, float y){
        sprite.setPosition(x,y);
    }

    float getX(){
        return sprite.getPosition().x
    }
  
    float getY() {
        return sprite.getPosition().y;
    }

    void moveRight(){
        //TODO
    }

    void moveLeft(){
        //TODO
    }
  
    float getSpeed(){
        //TODO implement
        return 0.01;
    }
    
    
    /*
    bool isCollidingWithCoin(Coin *coin) {
        if (player.getGlobalBounds().intersects(coin->getGlobalBounds())) {
            return true;
        }
        return false;
    }
    */
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float horizontalSpeed = 0.2;
    const float gravityConst = 0.3;


        
};
