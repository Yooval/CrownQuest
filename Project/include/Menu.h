#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>
#include "Button.h"
#include "Item.h"

const int windowWidth = 1300;
const int windowHeight = 800;

class Menu
{
public:
	Menu();
	void runMenu(sf::RenderWindow&);
	bool getStart() { return m_start; };
private:
	void mouseButtonReleased(sf::Event, sf::RenderWindow&, sf::Sprite);
	void drawHelp(sf::RenderWindow&, sf::Sprite);
	void mouseButtonReleasedHelp(sf::Event);
	void mouseMoved(sf::Event);
	void mouseMovedHelp(sf::Event, Button&);
	bool inWindow(sf::Event);
	std::vector<std::unique_ptr<Button>> m_menu;
	bool m_start = false;
	bool m_back = false;
};
