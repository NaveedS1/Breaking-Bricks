#include "Resource.h"

Resource::Resource()
{
	if (!font.loadFromFile("../Resource/font.otf"))
	{
		std::cout << "Couldn't load font\n";
	}
	this->playerScorce = 0;
	text.setPosition(sf::Vector2f(10, 550));
	text.setFont(font);
	text.setScale(sf::Vector2f(0.6, 0.6));
}

Resource::~Resource()
{
}

void Resource::updateScore(int point)
{
	playerScorce += point;
}

void Resource::update()
{
	text.setString("Player : " + std::to_string(this->playerScorce));
}

void Resource::draw(sf::RenderWindow & renWindow)
{
	renWindow.draw(text);
}
