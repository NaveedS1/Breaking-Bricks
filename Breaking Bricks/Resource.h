#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <iomanip>

class Resource
{
private:
	sf::Font font;
	sf::Text text;
	int playerScorce;

public:
	Resource();
	~Resource();

	void updateScore(int point);

	void update();
	void draw(sf::RenderWindow &renWindow);
};