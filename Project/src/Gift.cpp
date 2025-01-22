#include "Gift.h"
#include "Board.h"

void Gift::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Gift::collide(Dwarf& otherObject, Board& board) {
	;
}
void Gift::collide(King& otherObject, Board& board) {
	m_toDelete = true;
	action(board);
}
void Gift::collide(Mage& otherObject, Board& board) {
	m_toDelete = true;
	action(board);
}
void Gift::collide(Thief& otherObject, Board& board) {
	m_toDelete = true;
	action(board);
}
void Gift::collide(Warrior& otherObject, Board& board) {
	m_toDelete = true;
	action(board);
}