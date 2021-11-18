

#ifndef PLATFORMERGAME_GAMEENGINE_H
#define PLATFORMERGAME_GAMEENGINE_H
#include <SFML/Graphics.hpp>
#include "../object/Hero.h"

namespace engine {
    class GameEngine {

    public:

        //Functions
        void start();
        void initWindow();
        void drawObjects();

    private:



        //Variables
        std::vector<object::GameObject> game_objects;



    };
}
#endif //PLATFORMERGAME_GAMEENGINE_H
