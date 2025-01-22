#include "Wall.h"
#include "Board.h"

void Wall::collide(Item& otherObject,Board& board) {
	otherObject.collide(*this, board);
}

void Wall::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Wall::collide(King& otherObject, Board& board) {
	board.getSound("wall").play();
	otherObject.collide(*this, board);
}
void Wall::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Wall::collide(Thief& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Wall::collide(Warrior& otherObject, Board& board) {
	otherObject.collide(*this, board);
}