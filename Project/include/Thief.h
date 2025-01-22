#pragma once
#include "MovableItem.h"
#include <SFML/Graphics.hpp>

class Board;

class Thief: public MovableItem
{
public:
	Thief(sf::Vector2f, std::string);
	virtual void draw(sf::RenderWindow&);
	void setWithKey() { m_key = true; };
	void setWithoutKey() { m_key = false; };
	virtual void move(float, Board&);
	bool getKey() { return m_key; };
	virtual void collide(Item&, Board&);
	virtual void collide(Fire&, Board&);
	virtual void collide(Gate&, Board&);
	virtual void collide(Gift&, Board&);
	virtual void collide(Key&, Board&);
	virtual void collide(Orc&, Board&);
	virtual void collide(Teleport&, Board&);
	virtual void collide(Throne&, Board&);
	virtual void collide(Wall&, Board&);
	virtual void collide(Dwarf&, Board&);
	virtual void collide(Mage&, Board&);
	virtual void collide(King&, Board&);
	virtual void collide(Warrior&, Board&);
	
private:
	bool m_key = false;
	sf::Texture m_texKey;
	sf::Sprite m_sprKey;
};
