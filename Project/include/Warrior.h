#pragma once
#include "MovableItem.h"
#include <SFML/Graphics.hpp>

class Board;

class Warrior: public MovableItem
{
public:
	using MovableItem::MovableItem;
	virtual void draw(sf::RenderWindow&);
	virtual void move(float, Board&);
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
	virtual void collide(Thief&, Board&);
	virtual void collide(King&, Board&);
private:

};
