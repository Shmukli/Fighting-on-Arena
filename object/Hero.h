//
// Created by Banana on 31.10.2021.
//

#ifndef PLATFORMERGAME_HERO_H
#define PLATFORMERGAME_HERO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
namespace object {
    class Hero : public GameObject  {

    public:
        Hero() {
            loadSprite("C:/Users/Banana/CLionProjects/PlatformerGame/asset/PNG/Knight/Idle/idle1.png");
        }

        ~Hero() = default;

        //Functions




    private:

        //Variables
        float health;



    };
}
#endif //PLATFORMERGAME_HERO_H