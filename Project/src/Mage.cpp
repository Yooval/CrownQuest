#include "Mage.h"
#include "Board.h"

void Mage::draw(sf::RenderWindow& window) {
	//draw
	window.draw(m_sprite);
	if (m_isSelected) {
		m_outline.setPosition(m_sprite.getPosition());
		window.draw(m_outline);
	}
}
void Mage::move(float deltaTime, Board& board) {
	sf::Vector2f direction = board.getDirection();
	m_prevPosition = m_sprite.getPosition();
	sf::Vector2f dest = m_sprite.getPosition() + (direction * speedPerSecond * deltaTime);
	if (isInBoard(board, dest)) {
		m_sprite.setPosition(dest);
		for (int i = 0; i < board.getTiles().size(); ++i) {
			if (checkCollision(*board.getTile(i))) {
				collide(*board.getTile(i), board);
			}
		}
		for (int i = 0; i < board.getCharacters().size(); ++i) {
			if (checkCollision(*board.getCharacter(i)) && i != 1) {
				collide(*board.getCharacter(i), board);
			}
		}
		for (int i = 0; i < board.getDwarves().size(); ++i) {
			if (checkCollision(*board.getDwarf(i))) {
				collide(*board.getDwarf(i), board);
			}
		}
		board.deleteTiles();
	}
}


void Mage::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Mage::collide(Fire& otherObject, Board& board) {
	;
}
void Mage::collide(Gate& otherObject, Board& board) {
	goBack();
}
void Mage::collide(Gift& otherObject, Board& board) {
	;
}
void Mage::collide(Key& otherObject, Board& board) {
	;
}
void Mage::collide(Orc& otherObject, Board& board) {
	goBack();
}
void Mage::collide(Teleport& otherObject, Board& board) {
	goBack();
}
void Mage::collide(Throne& otherObject, Board& board) {
	goBack();
}
void Mage::collide(Wall& otherObject, Board& board) {
	goBack();
}
void Mage::collide(Dwarf& otherObject, Board& board) {
	otherObject.goBack();
	otherObject.collide(*this, board);
}
void Mage::collide(King& otherObject, Board& board) {
	otherObject.goBack();
}
void Mage::collide(Thief& otherObject, Board& board) {
	otherObject.goBack();
}
void Mage::collide(Warrior& otherObject, Board& board) {
	otherObject.goBack();
}