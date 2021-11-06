

#ifndef PLATFORMERGAME_GAMEOBJECT_H
#define PLATFORMERGAME_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>
namespace object {
class GameObject{
public:
    GameObject() = default;

    ~GameObject() = default;

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
