
#include "GameEngine.h"

void engine::GameEngine::initVaribles(){




}
void engine::GameEngine::update(){





}
engine::GameEngine::GameEngine(){

    initWindow();
    spawnHero(this->hero);
    drawHero(this->hero);




}
sf::RenderWindow* engine::GameEngine::getWindow(){

    return window;

}
engine::GameEngine::~GameEngine(){

    delete this->window;

}

const bool engine::GameEngine::isGameRunning()
{

return this->window->isOpen();

}
void engine::GameEngine::drawHero(object::Hero hero){

    this->window->draw(this->hero.getSprite());

}
void engine::GameEngine::spawnHero(object::Hero hero)
{

 hero.getSprite().setPosition(sf::Vector2f(0,0));

}


void engine::GameEngine::drawEnemies(object::Enemy enemy)
{

this->game_enemies.push_back(enemy);

}
void engine::GameEngine::start()
{

}

void engine::GameEngine::initWindow()
{

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "PlatformerGame", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);

}

