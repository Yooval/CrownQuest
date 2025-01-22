#include "Key.h"
#include "Board.h"

void Key::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Key::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Key::collide(King& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Key::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Key::collide(Thief& otherObject, Board& board) {
	if (!otherObject.getKey()) {
		m_toDelete = true;
	}
	otherObject.collide(*this, board);
}
void Key::collide(Warrior& otherObject, Board& board) {
	otherObject.collide(*this, board);
}