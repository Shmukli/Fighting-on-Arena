
#include "GameEngine.h"

void engine::GameEngine::initVaribles(){
     this->window = nullptr;




}
void engine::GameEngine::setBackGroundScale(){

    this->background_sprite.setScale(this->scale.x, this->scale.y);

}
void engine::GameEngine::calculateScaleOfWindow() {

    this->sizeOfWindow = this->window->getSize();
    this->scale.x = ((static_cast<float>(sizeOfWindow.x) / 2048));
    this->scale.y = ((static_cast<float>(sizeOfWindow.y) / 604));

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

    spawnHero();
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

    loadBackGround("../asset/PNG/background/Magic-Cliffs-Environment/PREVIEWS/magic-cliffs-preview-detail.png");
    setBackGroundScale();
    this->window->draw(this->background_sprite);

}

engine::GameEngine::GameEngine(){


    initWindow();





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

 hero.getSprite().setPosition(sf::Vector2f(0,250*scale.y));

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

