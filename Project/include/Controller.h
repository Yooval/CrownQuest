#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"
#include "Menu.h"

using std::ifstream;
using std::getline;
using std::string;

class Controller
{
public:
    Controller() { };
    void run();
private:
    sf::Clock m_clock;
    void drawNewStage(sf::RenderWindow&, int, int, int);
    void drawMessage(sf::RenderWindow&, int, int, int, string);
    void readNumOfLeveles(int&, std::vector<string>&);
};