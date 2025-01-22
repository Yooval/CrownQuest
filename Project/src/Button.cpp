#include "Button.h"

Button::Button(std::string text, sf::Vector2f pos):Item(pos,"blank.png") {
	m_buttonText = text;
}

void Button::draw(sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("menuFont.otf")) {
		std::cout << "Error, can not load font\n";
		exit(0);
	}

	std::ostringstream string;
	string << m_buttonText;
	
	//set text
	sf::Text text;
	text.setFont(font);
	text.setString(string.str());
	if (m_highlight)
		text.setFillColor(sf::Color::Red);
	else
		text.setFillColor(sf::Color::Blue);
	text.setPosition(m_sprite.getPosition());

	//set background
	sf::RectangleShape backGround;
	backGround.setSize(sf::Vector2f((float)PIC_SIZE * 4, (float)PIC_SIZE*2));
	backGround.setFillColor(sf::Color::Black);
	backGround.setPosition(m_sprite.getPosition());
	backGround.setOutlineThickness(2);
	backGround.setOutlineColor(sf::Color::Yellow);

	window.draw(backGround);
	window.draw(text);
}

void Button::setHighlight(bool val) {
	if (val == false)
		m_highlight = false;
	else
		m_highlight = true;
}