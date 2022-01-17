//
// Created by Banana on 31.10.2021.
//

#ifndef PLATFORMERGAME_HERO_H
#define PLATFORMERGAME_HERO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Animation.h"
namespace object {
    class Hero{

    public:
        Hero();

      ~Hero() { delete this->texture;};

        //Functions

        void setHealthCoefficient(int health_coefficient);

       //void attack() override;
       void leftAttack(float deltaTime);
       void rightAttack(float deltaTime);

       void moveRight(float deltaTime);
       void moveLeft(float deltaTime);


        void initAttackAnimation();
        void initAnimation();

        sf::Sprite& getSprite();
        void loadSprite(std::string filename);

        void setHealth(unsigned int Health);
        unsigned int& getHealth();











    private:




        Animation animation;

        sf::Vector2u imageBound;
        sf::Vector2u currentImage;

        sf::Sprite sprite;
        sf::Texture* texture;

        float totalTime;
        float switchTime;
        //Variables
        unsigned int health;



    };
}
#endif //PLATFORMERGAME_HERO_H
