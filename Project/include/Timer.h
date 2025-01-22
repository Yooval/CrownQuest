#pragma once

#include "Item.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>

class Timer: public Item
{
public:
	Timer(sf::Vector2f position);
	virtual void draw(sf::RenderWindow&);
	void setTimeGift(int);
	void updateTime(float);
	bool getOutOfTime() { return m_runOutOfTime; };
	void setWithTimer() { m_noTimer = false; };
	bool getNoTimer() { return m_noTimer; };
private:
	int m_minutes;
	int m_seconds;
	float m_tempSec;
	bool m_noTimer=true;
	bool m_runOutOfTime=false;
	sf::Font m_font;
	sf::Text m_text;
	sf::RectangleShape m_backGround;

};
