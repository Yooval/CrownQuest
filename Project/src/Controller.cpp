#include "Controller.h"


void Controller::run() {
    //load and play the background sond
    sf::SoundBuffer song;
    if (!song.loadFromFile("song.wav")) {
        exit(0);
    }
    sf::Sound sound(song);
    sound.setVolume(80);
    sound.play();

    //define window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Save The King",
        sf::Style::Titlebar | sf::Style::Close);
    
    //run selection menu
    Menu menu;
    while (menu.getStart() == false) {
        menu.runMenu(window);
    }
    //read and define number of levels
    std::vector<string> levels;
    int numOfLevels = 0;
    readNumOfLeveles(numOfLevels, levels);

    //define background for board
    sf::Texture texture;
    texture.loadFromFile("background.jpeg");
    sf::Sprite background;
    background.setTexture(texture);
    
    
    //loop for each stage
    for (int i = 0; i < numOfLevels && window.isOpen(); ++i) {
        //define the board and set scale to background
        Board board(levels[i]);
        int x = board.getWindowWidth();
        int y = board.getWindowHeight();
        background.setScale(sf::Vector2f(((float)x / background.getGlobalBounds().height),
            ((float)y / background.getGlobalBounds().height)));
        //draw new stage msg
        window.clear(sf::Color::Black);
        window.draw(background);
        drawNewStage(window, i, x ,y);
        window.display();
        sf::sleep(sf::Time(sf::seconds(1)));//show message for 2 seconds


        //loop for handling events
        m_clock.restart().asSeconds();
        float sumDelta = 0;//for timer calculations
        while (window.isOpen() && !board.getKingOnThrone() && !board.getOutOfTime()) {
            //draw stage
            window.clear(sf::Color::Black);
            window.draw(background);
            board.draw(window);
            window.display();

            auto event = sf::Event();
            float deltaTime = m_clock.restart().asSeconds();
            while(window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                    {
                        window.close();
                        break;
                    }

                    case sf::Event::KeyPressed:
                    {
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            window.close();
                            break;
                        }
                        else if (event.key.code == sf::Keyboard::Right ||
                            event.key.code == sf::Keyboard::Left ||
                            event.key.code == sf::Keyboard::Up ||
                            event.key.code == sf::Keyboard::Down) {
                            board.setDirection(event.key.code);
                            board.move(deltaTime);
                        }
                        else if (event.key.code == sf::Keyboard::P) {
                            board.setSelector();
                        }
                        break;
                    }
                    case sf::Event::KeyReleased:
                    {
                        if(event.key.code == sf::Keyboard::Right ||
                            event.key.code == sf::Keyboard::Left ||
                            event.key.code == sf::Keyboard::Up ||
                            event.key.code == sf::Keyboard::Down) {
                            board.setSteps();
                        }
                    }
                }
            }
            board.updateTime(deltaTime);
            board.moveDwarves(deltaTime);
            sumDelta += deltaTime;
            //change dwarves directions every 0.25 sec
            if (sumDelta > 0.25) {
                board.setDwarfDirection();
                sumDelta = 0;
            }
            
            //if king is on throne
            if (board.getKingOnThrone()) {
                std::string str = "You Have Completed stage ";
                drawMessage(window, i, x, y, str);
                sf::SoundBuffer sound;
                if (!sound.loadFromFile("soundVictory.wav")) {
                    exit(0);
                }
                sf::Sound soundFail(sound);
                soundFail.play();
                sf::sleep(sf::Time(sf::seconds(1)));
            }
            
            //if out of time
            if (board.getOutOfTime()) {
                std::cout << "out of time\n";
                std::string str = "You Have Failed stage ";
                drawMessage(window, i, x, y, str);
                sf::SoundBuffer sound;
                if (!sound.loadFromFile("soundFail.wav")) {
                    exit(0);
                }
                sf::Sound soundFail(sound);
                soundFail.play();
                sf::sleep(sf::Time(sf::seconds(1)));
                --i;
            }
        }
    }
}

void Controller::drawMessage(sf::RenderWindow& window, int i, int x, int y, string str) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error, can not load font\n";
        exit(0);
    }

    std::ostringstream string;
    string << str << i + 1 << "!";
    //set text
    sf::Text text;
    text.setFont(font);
    text.setString(string.str());
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f((float)x / 3, (float)y / 3));
    //set background
    sf::RectangleShape backGround;
    backGround.setSize(sf::Vector2f((float)PIC_SIZE * 10, (float)PIC_SIZE));
    backGround.setFillColor(sf::Color::Black);
    backGround.setPosition(sf::Vector2f((float)x / 3, (float)y / 3));
    window.draw(backGround);
    window.draw(text);
    window.display();
}

void Controller::drawNewStage(sf::RenderWindow& window, int i, int x, int y) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error, can not load font\n";
        exit(0);
    }

    std::ostringstream string;
    string << "Welcome To Stage " << i+1 << "!";

    //set text
    sf::Text text;
    text.setFont(font);
    text.setString(string.str());
    text.setFillColor(sf::Color::Black);
    text.setPosition(sf::Vector2f((float)x/3, (float)y/3));

    window.draw(text);
}

void Controller::readNumOfLeveles(int& numOfLevels, std::vector<string>& levels) {
    string str;
    ifstream file("levels.txt");
    //open levels.txt and read the levels files name from it
    while (!file.eof()) {
        getline(file, str);
        levels.push_back(str);
        ++numOfLevels;
    }
}


