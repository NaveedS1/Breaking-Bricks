#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>

class Resource
{
private:
	const int PLAYER_DEFAULT_LIVES = 3;

	sf::Font font;
	sf::Text text;
	/*sf::SoundBuffer buffer1;
	sf::Sound sound;*/
	int playerScore;
	int playerLives;
public:
	Resource();
	~Resource();

	void addScore(int point);
	/*void playBallHitsBricksSound();
	void playBounceBallSound();*/
	void update();
	void reset();
	void removeLife();
	int getLives() const;
	int getScore() const;
	void draw(sf::RenderWindow &renWindow) const;
};