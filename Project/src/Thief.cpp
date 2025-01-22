#include "Thief.h"
#include "Board.h"


Thief::Thief(sf::Vector2f position, std::string str) : MovableItem(position, str) {
	if (!m_texKey.loadFromFile("key.jpeg")) {
		std::cout << "Error, can not load picture\n";
		exit(0);
	}
	m_texKey.setSmooth(true);
	m_sprKey.setTexture(m_texKey);
	m_sprKey.setScale(sf::Vector2f((float)20 / m_sprKey.getLocalBounds().width,
		(float)20 / m_sprKey.getLocalBounds().height));
	m_sprKey.setPosition(m_sprite.getPosition());
}

void Thief::draw(sf::RenderWindow& window) {
	
	//draw
	window.draw(m_sprite);
	if (m_key) {
		m_sprKey.setPosition(m_sprite.getPosition());
		window.draw(m_sprKey);
	}
	if (m_isSelected) {
		m_outline.setPosition(m_sprite.getPosition());
		window.draw(m_outline);
	}
}
void Thief::move(float deltaTime, Board& board) {
	sf::Vector2f direction = board.getDirection();
	m_prevPosition = m_sprite.getPosition();
	sf::Vector2f dest = m_sprite.getPosition() + (direction * speedPerSecond * deltaTime);
	if (isInBoard(board, dest)) {
		m_sprite.setPosition(dest);
		for (int i = 0; i < board.getTiles().size(); ++i) {
			if (checkCollision(*board.getTile(i))) {
				collide(*board.getTile(i), board);
				break;
			}
		}
		for (int i = 0; i < board.getCharacters().size(); ++i) {
			if (checkCollision(*board.getCharacter(i)) && i != 3) {
				collide(*board.getCharacter(i), board);
				break;
			}
		}
		for (int i = 0; i < board.getDwarves().size(); ++i) {
			if (checkCollision(*board.getDwarf(i))) {
				collide(*board.getDwarf(i), board);
				break;
			}
		}
		board.deleteTiles();
	}
}


void Thief::collide(Item& otherObject, Board& board) {
	otherObject.collide(*this, board);
}
void Thief::collide(Fire& otherObject, Board& board) {
	goBack();
}
void Thief::collide(Gate& otherObject, Board& board) {
	if (m_key) {
		m_key = false;
	}
	else
		goBack();
}
void Thief::collide(Gift& otherObject, Board& board) {
	;
}
void Thief::collide(Key& otherObject, Board& board) {
	if (m_key == false) {
		m_key = true;
	}
}
void Thief::collide(Orc& otherObject, Board& board) {
	goBack();
}
void Thief::collide(Teleport& otherObject, Board& board) {
	m_sprite.setPosition(board.setTeleport(otherObject.getPosition()));
}
void Thief::collide(Throne& otherObject, Board& board) {
	goBack();
}
void Thief::collide(Wall& otherObject, Board& board) {
	goBack();
}
void Thief::collide(Dwarf& otherObject, Board& board) {
	otherObject.goBack();
	otherObject.collide(*this, board);
}
void Thief::collide(Mage& otherObject, Board& board) {
	otherObject.goBack();
}
void Thief::collide(King& otherObject, Board& board) {
	otherObject.goBack();
}
void Thief::collide(Warrior& otherObject, Board& board) {
	otherObject.goBack();
}