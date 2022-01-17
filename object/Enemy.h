//
// Created by Banana on 31.10.2021.
//

#ifndef PLATFORMERGAME_ENEMY_H
#define PLATFORMERGAME_ENEMY_H
#include "GameObject.h"
#include "Hero.h"
namespace object{
class Enemy{
public:
    Enemy();

     ~Enemy();


    //Functions


    //void attack() override;
    void leftAttackEnemy(float deltaTime);
    void rightAttackEnemy(float deltaTime);

    void moveRightEnemy(float deltaTime);
    void moveLeftEnemy(float deltaTime);

    void setHealthCoefficient(int health_coefficient);


    void initAttackAnimationEnemy();
    void initAnimationEnemy();

    sf::Sprite& getSpriteEnemy();
    void loadSpriteEnemy(std::string filename);

    void setHealth(unsigned int Health);
    unsigned int& getHealth();










private:



    Animation animationEnemy;

    sf::Vector2u imageBoundEnemy;
    sf::Vector2u currentImageEnemy;

    sf::Sprite spriteEnemy;
    sf::Texture* textureEnemy;

    float totalTimeEnemy;
    float switchTimeEnemy;
    //Variables
    unsigned int healthEnemy;

    void loadSprite(std::string filename);
};
}

#endif //PLATFORMERGAME_ENEMY_H
