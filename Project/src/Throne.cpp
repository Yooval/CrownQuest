#include "Throne.h"
#include "Board.h"

void Throne::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Throne::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Throne::collide(King& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Throne::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Throne::collide(Thief& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Throne::collide(Warrior& otherObject, Board& board) {
	otherObject.collide(*this, board);
}