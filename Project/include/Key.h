#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>

class Key: public Item
{
public:
	using Item::Item;
	virtual void collide(Item&, Board&);
	virtual void collide(Dwarf&, Board&);
	virtual void collide(King&, Board&);
	virtual void collide(Mage&, Board&);
	virtual void collide(Thief&, Board&);
	virtual void collide(Warrior&, Board&);
private:

};
