

#ifndef PLATFORMERGAME_GAMEENGINE_H
#define PLATFORMERGAME_GAMEENGINE_H
#include <SFML/Graphics.hpp>
#include "../object/Hero.h"
#include "../object/Enemy.h"
#include "../event/eventController.h"
#include "../physics/Collision.h"
#include <fstream>
#include <string>
struct players_score{
    bool firstPlayerWin;
    bool secondPlayerWin;
};

namespace engine {
    class GameEngine {

    public:
        GameEngine();
        ~GameEngine();

        //Functions
        void initVaribles();
        void start();
        void initWindow();

        unsigned int& getHeroHealth();
        unsigned int& getEnemyHealth();

        void drawEnemies(sf::RenderTarget& target);
        void spawnEnemy();
        void drawEnemy();
        void renderEnemy();
        object::Enemy& getEnemy();
        Collision getCollision();
        bool getCollisionResult();
        void setCollisionResult(bool collision_res);

        sf::Clock* getClock();
        float getDeltaTime();
        void setDeltaTime(sf::Clock* clock);

        void checkWhoWin();
        bool gameOver();

        void initHealthHero();

        void loadToFile();


        void initEnemyHealth();
        void updateEnemyHealth();

        void updateText();

        void renderText(sf::RenderTarget& target);


        object::Hero& getHero();
        void spawnHero();
        void drawHero();
        void renderHero();

        void updateHeroHealth();


        void update();
        void render();


        eventController& getEventController();
        void calculateScaleOfWindow();
        void setBackGroundScale();
        sf::RenderWindow* getWindow();
        const bool isGameRunning();
        void loadBackGround(std::string filename);
        void setGameField();

    private:

        players_score playersScore;

        std::ofstream myFile;

        sf::Font healthHeroFont;
        sf::Font healthEnemyFont;


        sf::Text heroHealth;
        sf::Text heroHealthDecription;
        std::string heroHealthString;
        sf::Text enemyHealth;
        sf::Text enemyHealthDecription;
        std::string enemyHealthString;
        //Variables
        unsigned int actualHeroHealth;
        unsigned int  actualEnemyHealth;

        float deltaTime;

        Collision collision;

        bool gameOverResult;

        bool collisionResult;

        sf::Clock* clock;
        eventController event_controller;

        sf::Texture background_texture;
        sf::Sprite  background_sprite;

        sf::Vector2u sizeOfWindow;
        sf::Vector2f scale;

        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        object::Hero hero;
        object::Enemy enemy;




    };
}
#endif //PLATFORMERGAME_GAMEENGINE_H
