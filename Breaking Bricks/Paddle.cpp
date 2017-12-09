#include "Paddle.h"

Paddle::Paddle(/*float startX, float startY*/)
{
	setDefColor(sf::Color::Green);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	rect.setSize({ rectWidth, rectHeight });
	setVelocity(sf::Vector2f{ -rectVelocity, -rectVelocity });
}

void Paddle::draw(sf::RenderWindow & Window)
{
	Window.draw(rect);
}

void Paddle::update()
{
	rect.move(getVelocity());
    
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
		&& getPositionEDGELEFTX() > -rect.getSize().x / 2)
		setVelocityX(-rectVelocity);
		//velocity.x = -rectVelocity;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		&& getPositionEDGERIGHTX() < getWindowWidth() - rect.getSize().x / 2)//
		//velocity.x = rectVelocity;
		setVelocityX(rectVelocity);
	
}

void Paddle::setPosition(float x, float y)
{
	DTPositionX = x;
	DTPositionY = y;
	rect.setPosition(sf::Vector2f(x, y));
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
