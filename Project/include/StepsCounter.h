#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>
#include "Item.h"


class StepsCounter: public Item
{
public:
	StepsCounter(sf::Vector2f position) : Item(position, "blank.png"), m_steps(0) { ; };
	virtual void draw(sf::RenderWindow&);
	void setSteps();

protected:
	int m_steps;
};
