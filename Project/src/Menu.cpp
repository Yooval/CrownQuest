#include "Menu.h"
Menu::Menu() {
	m_menu.resize(3);
	m_menu[0]= std::make_unique<Button>
		("New Game",sf::Vector2f((float)windowWidth / 2 - 100, (float)windowHeight/ 3 - 100));
	m_menu[1] = std::make_unique<Button>
		("Help", sf::Vector2f((float)windowWidth / 2 - 100, (float)(windowHeight / 2)));
	m_menu[2] = std::make_unique<Button> 
		("Exit", sf::Vector2f((float)windowWidth / 2 - 100, (float)(windowHeight / 3) * 2+100));
}
//------------------------------
void Menu::runMenu(sf::RenderWindow& window) {
	sf::Texture texture;
	texture.loadFromFile("background.jpeg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(((float)windowWidth / sprite.getGlobalBounds().height),
		((float)windowHeight / sprite.getGlobalBounds().height)));
	while (window.isOpen() && m_start == false) {
		window.clear(sf::Color::Black);
		window.draw(sprite);
		for (int i = 0; i < m_menu.size(); ++i) {
			m_menu[i]->draw(window);
		}
		sf::Event event;
		while (window.pollEvent(event) && m_start==false)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				mouseButtonReleased(event, window, sprite);
				break;
			case sf::Event::MouseMoved:
				if (inWindow(event))
					mouseMoved(event);
				break;
			}
		}
		window.display();
	}
}
//------------------------------
void Menu::mouseButtonReleased(sf::Event event, sf::RenderWindow& window, sf::Sprite sprite) {
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)y, (float)x);
	//new game
	if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= windowHeight / 3 - 100 && pos.x <= windowHeight / 3)
		m_start = true;
	//help
	else if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 2) && pos.x <= (windowHeight / 2+100)) {
		drawHelp(window, sprite);
	}
	//exit
	else if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 3) * 2 + 100 && pos.x <= (windowHeight / 3) * 2 + 200) {
		window.close();
		exit(0);
	}
}

//------------------------------
void Menu::drawHelp(sf::RenderWindow& window, sf::Sprite sprite) {
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error, can not load font\n";
		exit(0);
	}

	std::ostringstream string;
	string << 
		"                  The goal is help the king return to his throne.\n" <<
		"                               There are four characters:\n" <<
		"                                 King: Can use teleports.\n" <<
		"                                  Mage: Can put off fire.\n" <<
		"                     Warrior: Can use teleports and kill orcs.\n" <<
		"                       Thief: Can use teleports, pick up keys\n                  (that falls from dead orcs) and open gates.\n" <<
		"    You can pick up gifts along the way with every character, \n                             but not all gifts are good for you!\n" <<
		"                          Controls: use the arrows to move, \n                       and P to change the selected character.\n" <<
		"\n                 Note that there are dwarves that will block\n                                              your way!";
	
	//set background for text
	sf::Texture texture;
	sf::Sprite scroll;
	if (!texture.loadFromFile("scroll.jpeg")) {
		std::cout << "Error, can not load picture\n";
		exit(0);
	}
	scroll.setTexture(texture);
	scroll.setScale(sf::Vector2f((float)windowWidth / scroll.getLocalBounds().width,
		(float)windowHeight / scroll.getLocalBounds().height));
	scroll.setPosition(sf::Vector2f((float)0, (float)0));
	
	//set text
	sf::Text text;
	text.setFont(font);
	text.setString(string.str());
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f((float)200, (float)50));
	//set "back" button
	Button back("  Back To \n  Menu", sf::Vector2f((float)windowWidth / 2 - 100, (float)(windowHeight / 3) * 2 + 100));
	while (m_back == false) {
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.draw(scroll);
		window.draw(text);
		back.draw(window);
		//loop for finding is pressed back
		sf::Event event;
		while (window.pollEvent(event) && m_back == false)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				mouseButtonReleasedHelp(event);
				break;
			case sf::Event::MouseMoved:
				if (inWindow(event))
					mouseMovedHelp(event, back);
				break;
			}
		}
		window.display();
	}

}
//---------------------------------
void Menu::mouseButtonReleasedHelp(sf::Event event) {
	int y = event.mouseButton.x;
	int x = event.mouseButton.y;

	sf::Vector2f pos((float)x, (float)y);
	if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 3) * 2 + 100 && pos.x <= (windowHeight / 3) * 2 + 200)
		m_back = true;
}

//--------------------------------------
void Menu::mouseMoved(sf::Event event) {
	int y = event.mouseMove.x;
	int x = event.mouseMove.y;
	for (int i = 0; i < m_menu.size(); ++i) {
		m_menu[i]->setHighlight(false);
	}
	sf::Vector2f pos((float)x, (float)y);
	//new game
	if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= windowHeight / 3 - 100 && pos.x <= windowHeight / 3)
		m_menu[0]->setHighlight(true);
	//help
	else if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 2) && pos.x <= (windowHeight / 2 + 100)) {
		m_menu[1]->setHighlight(true);
	}
	//exit
	else if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 3) * 2+100 && pos.x <= (windowHeight / 3) * 2 + 200) {
		m_menu[2]->setHighlight(true);
	}
}

//--------------------------------------
void Menu::mouseMovedHelp(sf::Event event, Button& back) {
	int y = event.mouseMove.x;
	int x = event.mouseMove.y;
	back.setHighlight(false);
	
	sf::Vector2f pos((float)x, (float)y);
	if (pos.y >= windowWidth / 2 - 100 && pos.y <= windowWidth / 2 + 100
		&& pos.x >= (windowHeight / 3) * 2 + 100 && pos.x <= (windowHeight / 3) * 2 + 200)
		back.setHighlight(true);
}

//--------------------------------------
bool Menu::inWindow(sf::Event event)
{
	int y = event.mouseMove.x;
	int x = event.mouseMove.y;
	//sf::Vector2f pos((float)(x - (x % 50)), (float)(y - (y % 50)));

	if (x > 1000 || y > 1000 || x < 0 || y < 0)
		return false;
	return true;
}