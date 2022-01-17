

#ifndef PLATFORMERGAME_MENU_H
#define PLATFORMERGAME_MENU_H
#include "SFML/Graphics.hpp"
#include "iostream"
#include "fstream"
#include <string>
#include <streambuf>

#define MAX_NUMBER_OF_ITEMS 5

class Menu
{
public:
    Menu(float width, float height, int index);
    ~Menu();

    // sf::RenderWindow* getMenuWindow();
    // bool isMenuWindowOpen();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void initHistory();
    void showHistory();
    void initHistoryWindow(sf::Text& history);

    void showHelp();

private:

    sf::Texture helpScreen;

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text history;
    std::string information;


};

#endif //PLATFORMERGAME_MENU_H
