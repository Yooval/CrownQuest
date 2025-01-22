#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>

class Board;

class MovableItem: public Item
{
public:
    MovableItem(sf::Vector2f, std::string);
    virtual void draw(sf::RenderWindow&) { ; };
    virtual void move(float, Board&) { ; };
    void imSeleceted() { m_isSelected = true; };
    void imNotSeleceted() { m_isSelected = false; };
    bool isInBoard(Board&, sf::Vector2f);
    void goBack();

protected:
    sf::RectangleShape m_outline;
    bool m_isSelected = false;
    float speedPerSecond;
    sf::Vector2f m_prevPosition = sf::Vector2f((float)0, (float)0);
};


