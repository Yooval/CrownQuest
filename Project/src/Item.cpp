#include "Item.h"


Item::Item(sf::Vector2f position, std::string str) {
	if (!m_texture.loadFromFile(str)) {
		std::cout << "Error, can not load picture\n";
		exit(0);
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(sf::Vector2f((float)PIC_SIZE / m_sprite.getLocalBounds().width,
		(float)PIC_SIZE / m_sprite.getLocalBounds().height));
	m_sprite.setPosition(position);
}

void Item::draw(sf::RenderWindow& window) {
	//draw
	window.draw(m_sprite);
}

bool Item::checkCollision(Item& otherObject) {
	if (&otherObject)
		return (m_sprite.getGlobalBounds().intersects(otherObject.m_sprite.getGlobalBounds()));
	return false;
}