#include "Orc.h"
#include "Board.h"

void Orc::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}

void Orc::collide(Dwarf& otherObject, Board& board) {
	otherObject.collide(*this, board);;
}
void Orc::collide(King& otherObject, Board& board) {
	otherObject.collide(*this, board);;
}
void Orc::collide(Mage& otherObject, Board& board) {
	otherObject.collide(*this, board);;
}
void Orc::collide(Thief& otherObject, Board& board) {
	otherObject.collide(*this, board);;
}
void Orc::collide(Warrior& otherObject, Board& board) {
	//board.setEffect("orcSound.wav");
	board.getSound("orc").play();
	m_toDelete = true;
	board.getTiles().push_back(std::make_unique <Key>(m_sprite.getPosition(), "key.jpeg"));
}