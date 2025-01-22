#pragma once

#include "Item.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>


class Button: public Item
{
public:
	Button(std::string, sf::Vector2f);
	void setHighlight(bool);
	virtual void draw(sf::RenderWindow&);
protected:
	std::string m_buttonText;
	bool m_highlight = false;
};
