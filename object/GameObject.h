

#ifndef PLATFORMERGAME_GAMEOBJECT_H
#define PLATFORMERGAME_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"

namespace object {
class GameObject : public PhysicsObject{
public:
    GameObject() = default;

    virtual ~GameObject() {};

    //Functions

    sf::Sprite getSprite();
    void loadSprite(std::string filename);


private:

    //variables
    sf::Sprite sprite;
    sf::Texture texture;



};
}
#endif //PLATFORMERGAME_GAMEOBJECT_H
