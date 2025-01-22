#include "MovableItem.h"
#include "Board.h"

MovableItem::MovableItem(sf::Vector2f position, std::string str) : Item(position, str) {
	m_sprite.setScale(sf::Vector2f((float)CHAR_SIZE / m_sprite.getLocalBounds().width,
		(float)CHAR_SIZE / m_sprite.getLocalBounds().height));
	m_outline.setSize(sf::Vector2f((float)CHAR_SIZE, (float)CHAR_SIZE));
	m_outline.setFillColor(sf::Color::Transparent);
	m_outline.setPosition(m_sprite.getPosition());
	m_outline.setOutlineThickness(2);
	m_outline.setOutlineColor(sf::Color(47, 79, 79, 255));
	speedPerSecond = 500;
	m_prevPosition = m_sprite.getPosition();
}

bool MovableItem::isInBoard(Board& board, sf::Vector2f dest) {
	//take pic size from width and height
	if (dest.x >= 0 && dest.x <= (board.getBoardWidth()-1) * PIC_SIZE &&
		dest.y >= PIC_SIZE && dest.y <= board.getBoardHeight()* PIC_SIZE)
		return true;
	return false;
}

void MovableItem::goBack() {
	m_sprite.setPosition(m_prevPosition);
}