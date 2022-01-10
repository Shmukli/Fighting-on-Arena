
#include "GameEngine.h"

void engine::GameEngine::initVaribles(){
    spawnHero();
    loadBackGround("../asset/PNG/background/Magic-Cliffs-Environment/PREVIEWS/magic-cliffs-preview-detail.png");




}

eventController& engine::GameEngine::getEventController(){

    return *this->event_controller;

}

void engine::GameEngine::setBackGroundScale(){

    this->background_sprite.setScale(this->scale.x, this->scale.y);

}
void engine::GameEngine::calculateScaleOfWindow() {

    this->sizeOfWindow = this->window->getSize();
    this->scale.x = ((static_cast<float>(sizeOfWindow.x) / 2048));
    this->scale.y = ((static_cast<float>(sizeOfWindow.y) / 604));
}

object::Hero& engine::GameEngine::getHero(){

    return this->hero;

}




void engine::GameEngine::render(){

    this->window->clear();
    setGameField();
    renderHero();
    this->window->display();

}

void engine::GameEngine::renderEnemies(){



}

void engine::GameEngine::renderHero(){

    drawHero();

}
void engine::GameEngine::update(){





}

void engine::GameEngine::loadBackGround(std::string filename){

if(!(this->background_texture.loadFromFile(filename)));
    {
        std::cout << "Oops, something went wrong!";
    }
    this->background_sprite.setTexture(this->background_texture);



}

void engine::GameEngine::setGameField(){


    setBackGroundScale();
    this->window->draw(this->background_sprite);

}

engine::GameEngine::GameEngine(){


    initWindow();
    initVaribles();





}
sf::RenderWindow* engine::GameEngine::getWindow(){

    return this->window;

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

 this->hero.getSprite().setPosition(this->hero.getSprite().getPosition().x * this->scale.x,
                                    this->hero.getSprite().getPosition().y + 250 * this->scale.y);

}


void engine::GameEngine::drawEnemies(sf::RenderTarget &target)
{
     int i = 0;
    for(auto &enemy : *this->game_enemies)
    {

        target.draw(game_enemies->at(i).getSprite());
        ++i;

    }
}
void engine::GameEngine::start()
{

}

void engine::GameEngine::initWindow()
{

    this->videoMode.height = 1080;
    this->videoMode.width = 1920;
    this->window = new sf::RenderWindow(this->videoMode, "PlatformerGame", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);

    calculateScaleOfWindow();

}

