#include "Menu.h"

Menu::Menu(float width, float height, int index) {

  if (!font.loadFromFile("../asset/arial.ttf")) {
    std::cout << "Couldn't open font for menu!";
  }
  if (index == 1) {
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Blue);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Difficulty:(1 click + 100hp)");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("History");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Help");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Exit");
    menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

    selectedItemIndex = 0;
  }
  if (index == 2) {

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Blue);
    menu[0].setString("Yes");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("No");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    selectedItemIndex = 0;
  }

}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
  for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
    window.draw(menu[i]);
  }
}

void Menu::MoveUp() {
  if (selectedItemIndex - 1 >= 0) {
    menu[selectedItemIndex].setColor(sf::Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setColor(sf::Color::Blue);
  }
}

void Menu::MoveDown() {
  if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
    menu[selectedItemIndex].setColor(sf::Color::White);
    selectedItemIndex++;
    menu[selectedItemIndex].setColor(sf::Color::Blue);
  }
}

void Menu::showHistory() {

  initHistory();

  std::ifstream t("info.txt");

  t.seekg(0, std::ios::end);
  this->information.reserve(t.tellg());
  t.seekg(0, std::ios::beg);

  this->information.assign((std::istreambuf_iterator<char>(t)),
                           std::istreambuf_iterator<char>());

  this->history.setString(information);
  initHistoryWindow(this->history);

}

void Menu::initHistoryWindow(sf::Text &history) {

  sf::VideoMode videoMode1;
  videoMode1.height = 600;
  videoMode1.width = 600;

  sf::RenderWindow menuHistoryWindow(videoMode1, "History", sf::Style::Titlebar | sf::Style::Close);
  while (menuHistoryWindow.isOpen()) {
    sf::Event event_temp;
    while (menuHistoryWindow.pollEvent(event_temp)) {
      if (event_temp.type == sf::Event::KeyPressed) {
        if (event_temp.key.code == sf::Keyboard::Escape);
        menuHistoryWindow.close();
        if (event_temp.type == sf::Event::Closed)
          menuHistoryWindow.close();
      }
    }
    menuHistoryWindow.clear(sf::Color::Black);
    menuHistoryWindow.draw(history);
    menuHistoryWindow.display();

  }

}

void Menu::initHistory() {

  if (!this->font.loadFromFile("../asset/Cute Letters.ttf")) {
    std::cout << "Couldn't download font!";
  }

  this->history.setFont(font);
  this->history.setFillColor(sf::Color::Red);

}

void Menu::showHelp() {

  sf::VideoMode videoMode1;
  videoMode1.height = 512;
  videoMode1.width = 768;

  sf::RenderWindow menuHelpWindow(videoMode1, "Help", sf::Style::Titlebar | sf::Style::Close);
  while (menuHelpWindow.isOpen()) {
    sf::Event event_temp;
    while (menuHelpWindow.pollEvent(event_temp)) {
      if (event_temp.type == sf::Event::KeyPressed) {
        if (event_temp.key.code == sf::Keyboard::Escape);
        menuHelpWindow.close();
        if (event_temp.type == sf::Event::Closed)
          menuHelpWindow.close();
      }
    }

    this->helpScreen.loadFromFile("../asset/help_screen.png");
    sf::Sprite helpScreenToDraw;
    helpScreenToDraw.setTexture(helpScreen);
    menuHelpWindow.clear(sf::Color::Black);
    menuHelpWindow.draw(helpScreenToDraw);
    menuHelpWindow.display();

  }

}






