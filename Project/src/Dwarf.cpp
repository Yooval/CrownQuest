#include "Dwarf.h"
#include "Board.h"

void Dwarf::move(float deltaTime, Board& board) {
	sf::Vector2f direction = board.getDirection();
	m_prevPosition = m_sprite.getPosition();
	sf::Vector2f dest = m_sprite.getPosition() + (m_direction * speedPerSecond * deltaTime);
	if (isInBoard(board, dest)) {
		m_sprite.setPosition(dest);
		for (int i = 0; i < board.getTiles().size(); ++i) {
			if (checkCollision(*board.getTile(i))) {
				collide(*board.getTile(i), board);
			}
		}
		for (int i = 0; i < board.getCharacters().size(); ++i) {
			if (checkCollision(*board.getCharacter(i))) {
				collide(*board.getCharacter(i), board);
			}
		}
		for (int i = 0; i < board.getDwarves().size(); ++i) {
			if (checkCollision(*board.getDwarf(i))&& i!=m_pos) {
				collide(*board.getDwarf(i), board);
			}
		}
		board.deleteTiles();
	}
}
void Dwarf::setPos(int i) {
	m_pos = i;
}

void Dwarf::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Dwarf::collide(Fire& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Gate& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Gift& otherObject, Board& board) {
	;
}
void Dwarf::collide(Key& otherObject, Board& board) {
	;
}
void Dwarf::collide(Orc& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Teleport& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Throne& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Wall& otherObject, Board& board) {
	goBack();
}
void Dwarf::collide(Dwarf& otherObject, Board& board) {
	otherObject.goBack();
}
void Dwarf::collide(King& otherObject, Board& board) {
	otherObject.goBack();
}
void Dwarf::collide(Mage& otherObject, Board& board) {
	otherObject.goBack();
}
void Dwarf::collide(Thief& otherObject, Board& board) {
	otherObject.goBack();
}
void Dwarf::collide(Warrior& otherObject, Board& board) {
	otherObject.goBack();
}