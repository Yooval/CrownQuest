#include "King.h"
#include "Board.h"

void King::draw(sf::RenderWindow& window) {
	//draw
	window.draw(m_sprite);
	if (m_isSelected) {
		m_outline.setPosition(m_sprite.getPosition());
		window.draw(m_outline);
	}
		
}

void King::move(float deltaTime, Board& board){
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
			if (checkCollision(*board.getCharacter(i))&&i!=0) {
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



void King::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void King::collide(Fire& otherObject, Board& board) {
	goBack();
}
void King::collide(Gate& otherObject, Board& board) {
	goBack();
}
void King::collide(Gift& otherObject, Board& board) {
	;
}
void King::collide(Key& otherObject, Board& board) {
	;
}
void King::collide(Orc& otherObject, Board& board) {
	goBack();
}
void King::collide(Teleport& otherObject, Board& board) {
	m_sprite.setPosition(board.setTeleport(otherObject.getPosition()));
}
void King::collide(Throne& otherObject, Board& board) {
	board.setKingOnThrone();
}
void King::collide(Wall& otherObject, Board& board) {
	goBack();
}
void King::collide(Dwarf& otherObject, Board& board) {
	otherObject.goBack();
	otherObject.collide(*this, board);
}
void King::collide(Mage& otherObject, Board & board) {
	otherObject.goBack();
}
void King::collide(Thief& otherObject, Board& board) {
	otherObject.goBack();
}
void King::collide(Warrior& otherObject, Board& board) {
	otherObject.goBack();
}