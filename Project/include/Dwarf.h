#pragma once

#include <SFML/Graphics.hpp>
#include "MovableItem.h"

class King;
class Mage;
class Thief;
class Warrior;
class Fire;
class Gate;
class Gift;
class Key;
class Orc;
class Teleport;
class Throne;
class Wall;

class Dwarf : public MovableItem
{
public:
	using MovableItem::MovableItem;
	virtual void draw(sf::RenderWindow& window){ window.draw(m_sprite); };
	virtual void move(float deltaTime, Board& board);
	void setDirection(sf::Vector2f dir) { m_direction = dir; };
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
	virtual void collide(Thief&, Board&);
	virtual void collide(Warrior&, Board&);
	void setPos(int);
private:
	sf::Vector2f m_direction;
	int m_pos=0;
};
