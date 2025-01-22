#include "Timer.h"


Timer::Timer(sf::Vector2f position) : Item(position, "blank.png"), m_minutes(0), m_seconds(0), m_tempSec(0), m_noTimer(true) {
	int num = rand() % 2;
	if (num == 1) {
		m_noTimer = false;
		m_minutes = rand() % 2 + 2;
	}

	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Error, can not load font\n";
		exit(0);
	}

	std::ostringstream string;
	if (m_noTimer)
		string << "Time Passed: " << m_minutes << ":" << m_seconds;
	else
		string << "Time Left: " << m_minutes << ":" << m_seconds;

	//set text
	m_text.setFont(m_font);
	m_text.setString(string.str());
	m_text.setFillColor(sf::Color::Red);
	m_text.setPosition(m_sprite.getPosition());

	//set background
	m_backGround.setSize(sf::Vector2f((float)PIC_SIZE * 5, (float)PIC_SIZE));
	m_backGround.setFillColor(sf::Color::Black);
	m_backGround.setPosition(m_sprite.getPosition());
	m_backGround.setOutlineThickness(2);
	m_backGround.setOutlineColor(sf::Color::Yellow);
}

void Timer::draw(sf::RenderWindow& window) {
	std::ostringstream string;
	if (m_noTimer) {
		if (m_seconds < 10)
			string << "Time Passed: " << m_minutes << ":0" << m_seconds;
		else
			string << "Time Passed: " << m_minutes << ":" << m_seconds;
	}
	else {
		if (m_seconds < 10)
			string << "Time Left: " << m_minutes << ":0" << m_seconds;
		else
			string << "Time Left: " << m_minutes << ":" << m_seconds;
	}
	m_text.setString(string.str());

	window.draw(m_backGround);
	window.draw(m_text);
}
//-------------------------
void Timer::setTimeGift(int time) {
	if (time > 0) {
		m_seconds += time;
		m_minutes = (m_minutes + (m_seconds / 60));
		m_seconds = m_seconds % 60;
		m_tempSec = m_seconds;
	}
	else {
		m_seconds += time; //time is neg
		if (m_seconds <= 0 && m_minutes != 0) {
			m_seconds += 59;
			m_tempSec = m_seconds;
			--m_minutes;
		}
		//run out of time
		if (m_seconds <= 0 && m_minutes == 0)
			m_runOutOfTime = true;
	}
}
//-------------------------
void Timer::updateTime(float deltaTime)
{
	if (!m_noTimer)
	{
		m_tempSec -= deltaTime;
		m_seconds = m_tempSec;
		//run out of time
		if (m_seconds == 0 && m_minutes == 0)
			m_runOutOfTime = true;
		//set timer
		if (m_seconds == 0 && m_minutes != 0) {
			m_tempSec = 60;
			m_seconds = 60;
			--m_minutes;
		}
	}
	else
	{
		m_tempSec += deltaTime;
		m_seconds = m_tempSec;
		if (m_seconds == 60) {
			m_tempSec = 0;
			m_seconds = 0;
			++m_minutes;
		}
	}
}