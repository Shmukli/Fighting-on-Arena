#include "Hero.h"

object::Hero::Hero()
{

    texture = new sf::Texture;

this->health = 100;

    loadSprite("../asset/sprite_sheet.png");

    initAnimation();



}


void object::Hero::setHealthCoefficient(int health_coefficient){

    this->health = this->health * health_coefficient;

}

void object::Hero::initAnimation() {


    this->animation.setTexture(this->texture);
    this->animation.setImageCount(sf::Vector2u(6,4));
    this->animation.setSwitchTime(0.08f);
    this->animation.initSizeOfUvRect();
    this->sprite.setTextureRect(animation.getRect());

}




void object::Hero::moveLeft(float deltaTime){


    this->sprite.setPosition(this->sprite.getPosition().x - 4.0f,
                                this->sprite.getPosition().y);
    this->animation.update(1, deltaTime);
    this->sprite.setTextureRect(animation.getRect());


}

void object::Hero::moveRight(float deltaTime){

    this->sprite.setPosition(this->sprite.getPosition().x + 4.0f,
                                this->sprite.getPosition().y);


    this->animation.update(0, deltaTime);
    this->sprite.setTextureRect(animation.getRect());


}


void object::Hero::loadSprite(std::string filename)
{

    if(!texture->loadFromFile(filename))
    {
        std::cout << "Error occured!";
    }
    this->sprite.setTexture(*this->texture);



}





sf::Sprite& object::Hero::getSprite()
{

    return this->sprite;

}

void object::Hero::leftAttack(float deltaTime) {

    this->animation.update(3, deltaTime);
    this->sprite.setTextureRect(animation.getRect());

}
void object::Hero::rightAttack(float deltaTime) {



        this->animation.update(2, deltaTime);

        this->sprite.setTextureRect(animation.getRect());

}

unsigned int& object::Hero::getHealth() {

    return this->health;

}

void object::Hero::setHealth(unsigned int Health)
{

    this->health = Health;

}
/*void object::Hero::attack(){


}

void object::Hero::moveRight(){

    //TODO move and animation of move;

}



void object::Hero::moveLeft(){

    //TODO move and animation of move;

}*/