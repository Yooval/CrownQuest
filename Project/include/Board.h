#pragma once
#include "MovableItem.h"
#include "Fire.h"
#include "Gate.h"
#include "Key.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Orc.h"
#include "Teleport.h"
#include "Throne.h"
#include "Wall.h"
#include "StepsCounter.h"
#include "Timer.h"
#include "Gift.h"
#include "addTime.h"
#include "loseTime.h"
#include "killDwarves.h"
#include "Dwarf.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string.h>
#include <filesystem>
#include <SFML/Audio.hpp>

class Board 
{
public:
	Board(std::string);
	virtual void draw(sf::RenderWindow&);
	int getWindowWidth() { return m_windowWidth; };
	int getWindowHeight() { return m_windowHeight; };
	int getBoardWidth() { return m_boardWidth; };
	int getBoardHeight() { return m_boardHeight; };
	std::vector<std::unique_ptr<MovableItem>>& getCharacters();
	std::vector<std::unique_ptr<Dwarf>>& getDwarves();
	std::vector<std::unique_ptr<Item>>& getTiles();
	std::unique_ptr<Item>& getTile(int);
	std::unique_ptr<MovableItem>& getCharacter(int);
	std::unique_ptr<Dwarf>& getDwarf(int);
	void updateTime(float);
	void setSteps();
	void setTimeGift(int);
	void killDwarves();
	void setKingOnThrone();
	bool getKingOnThrone() { return m_kingOnThrone; };
	void move(float);
	void moveDwarves(float);
	sf::Vector2f setTeleport(sf::Vector2f);
	bool getOutOfTime();
	void setSelector();
	int getSelector() { return m_selector; };
	void setDirection(sf::Keyboard::Key);
	sf::Vector2f getDirection();
	void setDwarfDirection();
	void deleteTiles();
	sf::Sound getSound(std::string);

private:
	//private funcs
	void readSize();
	void readData();
	void setSounds();
	bool isInBoard(sf::Vector2f dest);
	void drawTiles(sf::RenderWindow&);
	
	//members
	std::vector<std::unique_ptr<Item>> m_tiles;
	std::vector<std::unique_ptr<MovableItem>> m_characters;
	std::vector<std::unique_ptr<Dwarf>> m_dwarves;
	std::vector<sf::Vector2f> m_teleportCells;
	int m_boardHeight;
	int m_boardWidth;
	int m_windowWidth;
	int m_windowHeight;
	std::fstream m_file;
	StepsCounter m_counter;
	Timer m_timer;
	int m_selector = 0; //for selectes character
	sf::Vector2f m_direction = sf::Vector2f(0, 0); //current direction
	sf::Vector2f m_dwarfDirection = sf::Vector2f(0, 0); //random dwarves directions
	bool m_kingOnThrone = false;
	
	//sounds
	sf::SoundBuffer fireBuf;
	sf::SoundBuffer gateBuf;
	sf::SoundBuffer orcBuf;
	sf::SoundBuffer teleportBuf;
	sf::SoundBuffer wallBuf;
	sf::Sound fire;
	sf::Sound gate;
	sf::Sound orc;
	sf::Sound teleport;
	sf::Sound wall;

};
