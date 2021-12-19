
#include "GameEngine.h"

void engine::GameEngine::initVaribles(){
     this->window = nullptr;




}
void engine::GameEngine::render(){

    this->window->clear();
    renderHero();
    this->window->display();

}

void engine::GameEngine::renderEnemies(){



}

void engine::GameEngine::renderHero(){

    spawnHero();
    drawHero();

}
void engine::GameEngine::update(){





}
engine::GameEngine::GameEngine(){

    initWindow();





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
void engine::GameEngine::drawHero(){

    this->window->draw(this->hero.getSprite());

}
void engine::GameEngine::spawnHero()
{

 hero.getSprite().setPosition(sf::Vector2f(0,0));

}


void engine::GameEngine::drawEnemies(sf::RenderTarget &target)
{
     int i = 0;
    for(auto &enemy : this->game_enemies)
    {

        target.draw(game_enemies[i].getSprite());
        ++i;

    }
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

