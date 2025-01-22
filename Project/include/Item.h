#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <iostream>


const int PIC_SIZE = 50;
const int CHAR_SIZE = 45;
class King;
class Dwarf;
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
class Board;
class Item
{
public:
	Item(sf::Vector2f, std::string);
	virtual void draw(sf::RenderWindow&);
	bool checkCollision(Item&);
	bool getToDelete() { return m_toDelete; };
	virtual void collide(Item&, Board&) { ; };
	virtual void collide(Fire&, Board&) { ; };
	virtual void collide(Gate&,Board&) { ; };
	virtual void collide(Gift&,Board&) { ; };
	virtual void collide(Key&, Board&) { ; };
	sf::Vector2f getPosition() { return m_sprite.getPosition(); };
	virtual void collide(Orc&, Board&) { ; };
	virtual void collide(Teleport&, Board&) { ; };
	virtual void collide(Throne&, Board&) { ; };
	virtual void collide(Wall&, Board&) { ; };
	virtual void collide(Dwarf&, Board&) { ; };
	virtual void collide(King&, Board&) { ; };
	virtual void collide(Mage&, Board&) { ; };
	virtual void collide(Thief&, Board&) { ; };
	virtual void collide(Warrior&, Board&) { ; };
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	bool m_toDelete = false;
};
