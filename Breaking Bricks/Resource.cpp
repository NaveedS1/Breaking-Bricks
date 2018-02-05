#include "Resource.h"

Resource::Resource()
{
	if (!font.loadFromFile("../Resource/font.otf"))
	{
		std::cout << "Couldn't load font\n";
	}
	this->playerScore = 0;
	this->playerLives = PLAYER_DEFAULT_LIVES;
	text.setPosition(sf::Vector2f(10, 550));
	text.setFont(font);
	text.setScale(sf::Vector2f(0.6, 0.6));

	/*if (!buffer1.loadFromFile("../Resource/bounce.wav"))
	{
		std::cout << " Error load sound effect 1\n";
	}*/
}

Resource::~Resource()
{
}

void Resource::addScore(int point)
{
	playerScore += point;
}

//void Resource::playBallHitsBricksSound()
//{
//	sound.setBuffer(buffer1);
//	sound.play();
//}

void Resource::update()
{
	// den måste anropas också
	text.setString("Players score : " + std::to_string(this->playerScore) + "\n" +
		"Lives : " + std::to_string(this->playerLives)); 
}

void Resource::reset()
{
	this->playerScore = 0;
	this->playerLives = PLAYER_DEFAULT_LIVES;
	update();
}

void Resource::removeLife()
{
	playerLives--;
}

int Resource::getLives() const 
{
	return playerLives;
}

int Resource::getScore() const
{
	return this->playerScore;
}

void Resource::draw(sf::RenderWindow & renWindow) const
{
	renWindow.draw(text);
}
