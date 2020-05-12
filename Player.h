#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GameObject.h"
 
class Player {
public:

    Player(std::string fileName, int size){
        spriteSize = size;
        if (!texture.loadFromFile("resources/ninja-black-32x32.png")){ std::cerr << "Incorrect texture load from file." << std::endl; }
        sprite.setTexture(texture);
        currSpriteRect = sf::IntRect(0,0,32,32);
        sprite.setTextureRect(currSpriteRect);
        sprite.setScale(2,2);
    }
  
    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
  
    void move(sf::Vector2f distance) {
        sprite.move(distance);
    }

    void move(float x, float y){
        sprite.move(x, y);
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
        numMoveCallsCurrSprite++;
        spriteState = 1;
        
        if(!getForwardFacing()) {
            resetSprite();
            unflipX();
        }         

        if(!getRunning()){
            //TODO set the sprite to start using the run sprite;
            currSpriteRect.left += spriteSize;
            sprite.setTextureRect(currSpriteRect);
            setRunning(true);
        }

        if(numMoveCallsCurrSprite % 20 == 0){
            //TODO: get cycle totally working instead of sticking on last 2 parts of it. (maybe a bool direction of cycle member variable?)
            if(getSpriteRunCycleLoc() == 3){
                spriteRunCycleLoc -= 1;
            } else {
                spriteRunCycleLoc += 1;
            }
            //TODO::
            int huh = numMoveCallsCurrSprite % 20;
            currSpriteRect.top = spriteRunCycleLoc * spriteSize;
            sprite.setTextureRect(currSpriteRect);
        }

        sprite.move(getHorizontalSpeed(), 0);
    }

    void moveLeft(){
        //TODO:: finish cycle animation in moveRight function then appropriately copy it here.
        numMoveCallsCurrSprite++;
        spriteState = 1;
        
        if(getForwardFacing()){
            resetSprite();
            flipX();
        }


        if(!getRunning()){
            //TODO set the sprite to start using the run sprite 
            //
            currSpriteRect.left += spriteSize;
            sprite.setTextureRect(currSpriteRect);
            setRunning(true);

        }
        
        
        

        sprite.move(-1*getHorizontalSpeed(),0);
    }
  
    float getHorizontalSpeed(){
        return horizontalSpeed;
    }

    void updateHorizontalSpeed(float newSpeed){
        //TODO:: figure out horizontal speed. Not happy with its current state.
        horizontalSpeed += newSpeed;
    }

    float getVerticalSpeed(){
        return verticalSpeed;
    }
    
    bool getForwardFacing(){
        return forwardFacing;
    }

    void resetSprite(){
        
        numMoveCallsCurrSprite = 0;
        spriteRunCycleLoc = 0;
        if(getForwardFacing()){
            currSpriteRect.width = spriteSize;
            currSpriteRect.left = 0;
            currSpriteRect.top = 0;
        } else {
            currSpriteRect.width = -spriteSize;
            currSpriteRect.left = spriteSize;
            currSpriteRect.top = 0;
        }
        sprite.setTextureRect(currSpriteRect);
        setRunning(false);
        //TODO::what else do we need to reset?
    }

    float getGravityConst(){
        return gravityConst;
    }

    int getCurrMoveSpriteCalls(){
        return numMoveCallsCurrSprite;
    }

    int getSpriteState(){
        return spriteState;
    }

    bool getRunning(){
        return isRunning;
    }

    void setRunning(bool newRunning){
        isRunning = newRunning;
    }

    int getSpriteRunCycleLoc(){
        return spriteRunCycleLoc;
    }

    void update(){
        verticalSpeed += getGravityConst();
        
        //TODO: see updateHorizontalSpeed.
        //
        //sprite.move( ??? , getVerticalSpeed() );
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
    sf::IntRect currSpriteRect;    
    
    float horizontalSpeed = 4;
    float verticalSpeed = 0;
    const float horizontalConst = 2;
    const float gravityConst = 0.3;
    int spriteSize;

    bool isRunning = false;
    //spriteCycleLoc is which sprite in the cycle of the run animation we are currently on. There are 4 total.
    int spriteRunCycleLoc = 0;
    
    //sprite state:: 0 = idle, 1 = moving, 2 = ??? TODO build this out as features are added. (attacking, jumping, falling, etc.);
    int spriteState = 0;

    int numMoveCallsCurrSprite = 0;
    bool forwardFacing = true; //1 is right facing, 0 is left facing
    
    // flip X
    void flipX(){
        forwardFacing = false;
        currSpriteRect.left += spriteSize;
        currSpriteRect.width *= -1;
        sprite.setTextureRect(currSpriteRect);
    }

    // unflip X
    void unflipX(){
        forwardFacing = true;
        currSpriteRect.left -= spriteSize;
        currSpriteRect.width *= -1;
        sprite.setTextureRect(currSpriteRect);
    }
        
};
