#include "Board.h"
#include "MovableItem.h"

Board::Board(std::string file):m_counter(sf::Vector2f((float)0, (float)0)), m_timer(sf::Vector2f((float)PIC_SIZE*6, (float)0)) {
    m_file.open(file);
    readSize();
    readData();
    setSelector();
    setSounds();
}

void Board::readSize() {
    m_boardWidth = 0, m_boardHeight = 0;
    int current_len = 0;
	while (!m_file.eof()) {
		std::string temp;
		std::getline(m_file, temp);
		current_len = (int)temp.length();
		if (current_len > m_boardWidth)
            m_boardWidth = current_len;
		++m_boardHeight;
	}
    //window height is board height+50 (toolbar height)
    m_windowWidth = m_boardWidth * PIC_SIZE;
    m_windowHeight = m_boardHeight * PIC_SIZE + PIC_SIZE;
    //set characters size
    m_characters.resize(4);
}

void Board::readData() {
    m_file.seekg(0);
    srand(100);
    for (int i = 0; i < m_boardHeight; ++i) {
        for (int j = 0; j < m_boardWidth; ++j) {
            char current = (char)m_file.get();
            if (current == '\n') {
                current = (char)m_file.get();
            }
            sf::Vector2f position((float)j * PIC_SIZE, (float)i * PIC_SIZE + PIC_SIZE);
            switch (current) {
            case '=': {
                m_tiles.push_back(std::make_unique <Wall>(position, "wall.jpeg"));
                break;
            }
            case '*': {
                m_tiles.push_back(std::make_unique <Fire>(position, "fire.jpeg"));
                break;
            }
            case 'F': {
                m_tiles.push_back(std::make_unique <Key>(position, "key.jpeg"));
                break;
            }
            case '!': {
                m_tiles.push_back(std::make_unique <Orc>(position, "orc.jpeg"));
                break;
            }
            case '#': {
                m_tiles.push_back(std::make_unique <Gate>(position, "gate.jpeg"));
                break;
            }
            case 'X': {
                m_tiles.push_back(std::make_unique <Teleport>(position, "teleport.jpeg"));
                m_teleportCells.push_back(position);
                break;
            }
            case '@': {
                m_tiles.push_back(std::make_unique <Throne>(position, "throne.jpeg"));
                break;
            }
            case 'K': {
                //insert king
                m_characters[0] = std::make_unique <King>(position, "king.jpeg");
                break;
            }
            case 'M': {
                //insert Mage
                m_characters[1] = std::make_unique <Mage>(position, "mage.jpeg");
                break;
            }
            case 'W': {
                //insert Warrior
                m_characters[2] = std::make_unique <Warrior>(position, "warrior.jpeg");
                break;
            }
            case 'T': {
                //insert Thief
                m_characters[3] = std::make_unique <Thief>(position, "thief.jpeg");
                break;
            }
            case '^': {
                //insert dwarf
                m_dwarves.push_back(std::make_unique <Dwarf>(position, "dwarf.jpeg"));
                break;
            }
            case ' ': {
                int giftType = rand() % 80; //gifts ratio is 3/80 or 1/80 if no timer
                if (m_timer.getNoTimer()) {
                    if (giftType == 1)//killDwarves
                    {
                        m_tiles.push_back(std::make_unique <KillDwarves>(position, "gift.jpeg"));
                    }
                }
                else{
                    
                    if (giftType == 1)//killDwarves
                    {
                        m_tiles.push_back(std::make_unique <KillDwarves>(position, "gift.jpeg"));
                    }
                    else if (giftType == 2)//addTime
                    {
                        m_tiles.push_back(std::make_unique <AddTime>(position, "gift.jpeg"));
                    }
                    else if (giftType == 3)//loseTime
                    {
                        m_tiles.push_back(std::make_unique <LoseTime>(position, "gift.jpeg"));
                    }
                    else //empty
                    {
                        ;
                    }
                }
                break;
            }            
            }
        }
    }
    if (m_teleportCells.size() % 2 != 0) {
        std::cout << "Invalid number of teleport cells\n";
        EXIT_FAILURE;
    }
    for (int i = 0; i < m_dwarves.size(); ++i) {
        m_dwarves[i]->setPos(i);
    }
}

void Board::setSounds() {
    if (!fireBuf.loadFromFile("soundFire.wav")) {
        exit(0);
    }
    fire.setBuffer(fireBuf);

    if (!wallBuf.loadFromFile("wallSound.wav")) {
        exit(0);
    }
    wall.setBuffer(wallBuf);

    if (!orcBuf.loadFromFile("orcSound.wav")) {
        exit(0);
    }
    orc.setBuffer(orcBuf);

    if (!gateBuf.loadFromFile("soundGate.wav")) {
        exit(0);
    }
    gate.setBuffer(gateBuf);

    if (!teleportBuf.loadFromFile("soundTeleport.wav")) {
        exit(0);
    }
    teleport.setBuffer(teleportBuf);

}

sf::Sound Board::getSound(std::string str) {
    if (str == "fire")
        return fire;
    else if (str == "wall")
        return wall;
    else if (str == "gate")
        return gate;
    else if (str == "orc")
        return orc;
    else if (str == "teleport")
        return teleport;
}
//general drawing
void Board::draw(sf::RenderWindow& window) {    
    m_counter.draw(window);
    m_timer.draw(window);
    drawTiles(window);
}

//draw the tiles
void Board::drawTiles(sf::RenderWindow& window) {
    //int selector;
    for (int i = 0; i < m_tiles.size(); ++i) {
        m_tiles[i]->draw(window);
    }
    for (int i = 0; i < m_characters.size(); ++i) {
        m_characters[i]->draw(window);
    }
    for (int i = 0; i < m_dwarves.size(); ++i) {
        m_dwarves[i]->draw(window);
    }
}



void Board::move(float deltaTime){
    m_characters[m_selector]->move(deltaTime, *this);
}

void Board::moveDwarves(float deltaTime) {
    for (int i=0; i<m_dwarves.size();++i)
        m_dwarves[i]->move(deltaTime, *this);
}

//default function for all char's to check if destination is inside the board limits
bool Board::isInBoard(sf::Vector2f dest) {
    if (dest.y >= 0 || dest.y < m_boardHeight ||
        dest.x >= 0 || dest.x < m_boardWidth)
        return true;
    return false;
}

void Board::updateTime(float deltaTime) {
    m_timer.updateTime(deltaTime);
}

void Board::setTimeGift(int time){
    m_timer.setTimeGift(time);
}

void Board::setSteps() {
    m_counter.setSteps();
}

void Board::killDwarves() {
    m_dwarves.resize(0);
}

void Board::setKingOnThrone() {
    m_kingOnThrone = true;
}

bool Board::getOutOfTime() {
    return m_timer.getOutOfTime(); 
}

void Board::setSelector() {
    ++m_selector; 
    m_selector = m_selector % 4; 
    for (int i = 0; i < m_characters.size(); ++i) {
        if (i == m_selector) {
            m_characters[i]->imSeleceted();
        }
        else {
            m_characters[i]->imNotSeleceted();
        }
    }
}
std::vector<std::unique_ptr<Item>>& Board::getTiles() {
    return m_tiles;
}
std::vector<std::unique_ptr<MovableItem>>& Board::getCharacters() {
    return m_characters;
}
std::vector<std::unique_ptr<Dwarf>>& Board::getDwarves() {
    return m_dwarves;
}

std::unique_ptr<Item>& Board::getTile(int i) {
    return m_tiles[i];
}

std::unique_ptr<MovableItem>& Board::getCharacter(int i) {
    return m_characters[i];
}

std::unique_ptr<Dwarf>& Board::getDwarf(int i) {
    return m_dwarves[i];
}
void Board::setDirection(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Up)
        m_direction = sf::Vector2f(0, -1);
    else if (key == sf::Keyboard::Down)
        m_direction = sf::Vector2f(0, 1);
    else if (key == sf::Keyboard::Left)
        m_direction = sf::Vector2f(-1, 0);
    else if (key == sf::Keyboard::Right)
        m_direction = sf::Vector2f(1, 0);
    else
        m_direction = sf::Vector2f(0, 0);
}
void Board::setDwarfDirection() {
    int num;
    for (int i = 0; i < m_dwarves.size(); ++i) {
        num = rand() % 4;
        switch (num) {
            case 0: {
                m_dwarves[i]->setDirection(sf::Vector2f(0, -1));
                break;
            }
            case 1: {
                m_dwarves[i]->setDirection(sf::Vector2f(0, 1));
                break;
            }
            case 2: {
                m_dwarves[i]->setDirection(sf::Vector2f(1, 0));
                break;
            }
            case 3: {
                m_dwarves[i]->setDirection(sf::Vector2f(-1, 0));
                break;
            }
        }
       
    }
}

sf::Vector2f Board::getDirection() { 
    return m_direction; 
}

sf::Vector2f Board::setTeleport(sf::Vector2f dest) {
    for (int i = 0; i < m_teleportCells.size(); ++i) {
        if (dest == m_teleportCells[i]) {
            if (i % 2 == 0) {
                return (sf::Vector2f(m_teleportCells[i + 1].x+PIC_SIZE, m_teleportCells[i + 1].y));
            }
            else {
                return (sf::Vector2f(m_teleportCells[i - 1].x + PIC_SIZE, m_teleportCells[i - 1].y));
            }
        }
    }
}

void Board::deleteTiles() {
    for (int i = 0; i < m_tiles.size(); ++i) {
        if (m_tiles[i]->getToDelete())
            m_tiles.erase(m_tiles.begin() + i);
    }
}

