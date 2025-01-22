#pragma once

#include <SFML/Graphics.hpp>
#include "Item.h"

class Throne: public Item
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
