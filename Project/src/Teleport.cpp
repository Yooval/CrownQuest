#include "Teleport.h"
#include "Board.h"

void Teleport::collide(Item& otherObject,Board& board) {
	otherObject.collide(*this, board);
}

void Teleport::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Teleport::collide(King& otherObject, Board& board) {
	//board.setEffect("soundTeleport.wav");
	board.getSound("teleport").play();
	otherObject.collide(*this, board);
}
void Teleport::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Teleport::collide(Thief& otherObject, Board& board) {
	board.getSound("teleport").play();
	otherObject.collide(*this, board);
}
void Teleport::collide(Warrior& otherObject, Board& board) {
	board.getSound("teleport").play();
	otherObject.collide(*this, board);
}