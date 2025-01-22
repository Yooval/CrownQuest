#include "Warrior.h"
#include "Board.h"

void Warrior::draw(sf::RenderWindow& window) {
	//draw
	window.draw(m_sprite);
	if (m_isSelected) {
		m_outline.setPosition(m_sprite.getPosition());
		window.draw(m_outline);
	}
}

void Warrior::move(float deltaTime, Board& board) {
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
			if (checkCollision(*board.getCharacter(i)) && i != 2) {
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


void Warrior::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Warrior::collide(Fire& otherObject, Board& board) {
	goBack();
}
void Warrior::collide(Gate& otherObject, Board& board) {
	goBack();
}
void Warrior::collide(Gift& otherObject, Board& board) {
	;
}
void Warrior::collide(Key& otherObject, Board& board) {
	;
}
void Warrior::collide(Orc& otherObject, Board& board) {
	;
}
void Warrior::collide(Teleport& otherObject, Board& board) {
	m_sprite.setPosition(board.setTeleport(otherObject.getPosition()));
}
void Warrior::collide(Throne& otherObject, Board& board) {
	goBack();
}
void Warrior::collide(Wall& otherObject, Board& board) {
	goBack();
}
void Warrior::collide(Dwarf& otherObject, Board& board) {
	otherObject.goBack();
	otherObject.collide(*this, board);
}
void Warrior::collide(Mage& otherObject, Board& board) {
	otherObject.goBack();
}
void Warrior::collide(Thief& otherObject, Board& board) {
	otherObject.goBack();
}
void Warrior::collide(King& otherObject, Board& board) {
	otherObject.goBack();
}