#include "StepsCounter.h"

void StepsCounter::draw(sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("font.ttf")){
		std::cout << "Error, can not load font\n";
		exit(0);
	}
	
	std::ostringstream string;
	string << "Steps Counter: " << m_steps;
	//set text
	sf::Text text;
	text.setFont(font);
	text.setString(string.str());
	text.setFillColor(sf::Color::Red);
	text.setPosition(m_sprite.getPosition());
	
	//set background
	sf::RectangleShape backGround;
	backGround.setSize(sf::Vector2f((float)PIC_SIZE*5, (float)PIC_SIZE));
	backGround.setFillColor(sf::Color::Black);
	backGround.setPosition(m_sprite.getPosition());
	backGround.setOutlineThickness(2);
	backGround.setOutlineColor(sf::Color::Yellow);
	
	window.draw(backGround);
	window.draw(text);
}

void StepsCounter::setSteps() {
	++m_steps;
}
