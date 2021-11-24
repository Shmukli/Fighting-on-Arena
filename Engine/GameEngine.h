

#ifndef PLATFORMERGAME_GAMEENGINE_H
#define PLATFORMERGAME_GAMEENGINE_H
#include <SFML/Graphics.hpp>
#include "../object/Hero.h"
#include "../object/Enemy.h"
#include "../event/eventController.h"

namespace engine {
    class GameEngine {

    public:
        GameEngine();
        ~GameEngine();

        //Functions
        void initVaribles();
        void start();
        void initWindow();
        void drawEnemies(object::Enemy enemy);
        void spawnHero(object::Hero hero);
        void drawHero(object::Hero hero);
        void spawnEnemy(object::Enemy enemy);
        void drawEnemy(object::Enemy enemy);
        void updateEnemies(object::Enemy enemy);
        void update();
        void render();
        void renderHero();
        void renderEnemies();
        sf::RenderWindow* getWindow();
        const bool isGameRunning();

    private:



        //Variables
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        std::vector<object::Enemy> game_enemies;
        object::Hero hero;



    };
}
#endif //PLATFORMERGAME_GAMEENGINE_H
