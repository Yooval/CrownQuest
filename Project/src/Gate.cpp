#include "Gate.h"
#include "Board.h"

void Gate::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Gate::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Gate::collide(King& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Gate::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Gate::collide(Thief& otherObject, Board& board) {
	if (otherObject.getKey()) {
		board.getSound("gate").play();
		m_toDelete = true;
	}
	otherObject.collide(*this, board);
}
void Gate::collide(Warrior& otherObject, Board& board) {
	otherObject.collide(*this, board);
}