#include "Paddle.h"

Paddle::Paddle()
{
	createPaddle();
}

Paddle::Paddle(unsigned int windowWidth, unsigned int windowHeight) : Entity(windowWidth, windowHeight)
{
	createPaddle();
}

void Paddle::createPaddle()
{
	setDefColor(sf::Color::Green);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	rect.setSize({ rectWidth, rectHeight });
	reset();
}

void Paddle::draw(sf::RenderWindow & window)
{
	window.draw(rect);
}

void Paddle::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
		&& getPositionEDGELEFTX() > -rect.getSize().x / 2)
	{
		setPositionX(getPosition().x - paddleSpeed);
		rect.move(sf::Vector2f(-paddleSpeed, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		&& getPositionEDGERIGHTX() < getWindowWidth() - rect.getSize().x / 2)
	{
		setPositionY(getPosition().x + paddleSpeed);
		rect.move(sf::Vector2f(paddleSpeed, 0));
	}
}

void Paddle::setPosition(float x, float y)
{
	DTPositionX = x;
	DTPositionY = y;
	rect.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Paddle::getPosition() const
{
	return sf::Vector2f(rect.getPosition());
}

bool Paddle::isWithinBounds()
{
	if (0 <= (rect.getPosition().x) && (rect.getPosition().x + rect.getSize().x) <= rectWidth)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}

bool Paddle::goRight()
{
	if (0 <= (rect.getPosition().x))
	{ 
		return true;
	}
	else {
		return false;
	}
}

bool Paddle::goLeft()
{
	if ((rect.getPosition().x + rect.getSize().x) <= rectWidth) 
	{ 
		return true; 
	}
	else
	{
		return false;
	}
}

Paddle::~Paddle()
{

}

void Paddle::paddleMovementLiveInput()
{
	if (isWithinBounds())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			rect.move(sf::Vector2f(-DTMoveX, DTMoveY));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			rect.move(sf::Vector2f(DTMoveX, DTMoveY));
		}
	}

	else if (goLeft()) { rect.move(sf::Vector2f(-1.f, 0.f)); }
	else if (goRight()) { rect.move(sf::Vector2f(1.f, 0.f)); }
}

float Paddle::getPositionEDGERIGHTX()
{
	return (rect.getPosition().x + rect.getSize().x / 2);
}

float Paddle::getPositionEDGETOPY()
{
	return (rect.getPosition().y - rect.getSize().y / 2);
}

float Paddle::getPositionEDGELEFTX()
{
	return (rect.getPosition().x - rect.getSize().x / 2);
}

float Paddle::getPositionEDGEDOWNY()
{
	return (rect.getPosition().y + rect.getSize().y / 2);
}

float Paddle::getCenterPositionX()
{
	return rect.getPosition().x;
}

float Paddle::getRectWidth()
{
	return rectWidth;
}

float Paddle::getRectHeight()
{
	return rectHeight;
}

void Paddle::reset()
{
	rect.setPosition(getWindowWidth() / 2 - getRectWidth() / 2, getWindowHeight() - getRectHeight());
}