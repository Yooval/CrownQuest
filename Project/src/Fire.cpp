#include "Fire.h"
#include "Board.h"

void Fire::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Fire::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Fire::collide(King& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Fire::collide(Mage& otherObject, Board& board) {
	//turn off fire
	//board.setEffect("soundFire.wav");
	board.getSound("fire").play();
	m_toDelete = true;
	otherObject.collide(*this, board);
}
void Fire::collide(Thief& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Fire::collide(Warrior& otherObject, Board& board) {
	otherObject.collide(*this, board);
}