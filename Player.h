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

    Player(std::string fileName, int size){
        spriteSize = size;
        if (!texture.loadFromFile("resources/ninja-black-32x32.png")){ std::cerr << "Incorrect texture load from file." << std::endl; }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0,0,32,32));
        sprite.setScale(2,2);
        
    }
  
    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
  
    void move(sf::Vector2f distance) {
        sprite.move(distance);
    }
  
    void setPos(sf::Vector2f newPos) {
        sprite.setPosition(newPos);
    }

    void setPos(float x, float y){
        sprite.setPosition(x,y);
    }

    float getX(){
        return sprite.getPosition().x;
    }
  
    float getY() {
        return sprite.getPosition().y;
    }

    void moveRight(){
        sprite.move(getHorizontalSpeed(), 0);
    }

    void moveLeft(){
        sprite.move(-1*getHorizontalSpeed(),0);
    }
  
    float getHorizontalSpeed(){
        return horizontalSpeed;
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
    float horizontalSpeed = 4;
    const float gravityConst = 0.3;
    int spriteSize;

        
};
