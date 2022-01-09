

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
        void drawEnemies(sf::RenderTarget& target);
        void spawnHero();
        void drawHero();
        void spawnEnemy();
        void drawEnemy();
        void updateEnemies();
        void update();
        void render();
        void renderHero();
        void renderEnemies();
        void calculateScaleOfWindow();
        void setBackGroundScale();
        sf::RenderWindow* getWindow();
        const bool isGameRunning();
        void loadBackGround(std::string filename);
        void setGameField();

    private:



        //Variables

        sf::Texture background_texture;
        sf::Sprite  background_sprite;

        sf::Vector2u sizeOfWindow;
        sf::Vector2f scale;

        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        std::vector<object::Enemy>* game_enemies;
        object::Hero hero;
        object::Enemy enemy;




    };
}
#endif //PLATFORMERGAME_GAMEENGINE_H
