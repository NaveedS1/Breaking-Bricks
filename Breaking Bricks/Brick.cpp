#include "Brick.h"
#include <iostream>

Brick::Brick() 
{
	this->isDestroyed = false;
}

Brick::Brick(float outlineThickness, float width, float height)
{
	brick.setFillColor(defColor);
	brick.setOutlineColor(defColorOutLine);
	brick.setSize(sf::Vector2f(width, height));
	brick.setOutlineThickness(outlineThickness);
	setSize(sf::Vector2i(width, height));
}

Brick & Brick::operator=(const Brick & oBrick)
{
	this->brick = oBrick.brick;
	setSize(sf::Vector2i(brick.getSize().x, brick.getSize().y));
	this->isDestroyed = oBrick.isDestroyed;
	this->defColor = oBrick.defColor;
	this->defColorOutLine = oBrick.defColorOutLine;

	return *this;
}

//void Brick::setPosition(const float x, const float y)
//{
	//position = sf::Vector2f(x, y);
//}

//float Brick::xPosition() const
//{
//	return brick.getPosition().x;
//}
//
//float Brick::yPosition() const
//{
//	return brick.getPosition().y;
//}

float Brick::width() const
{
	return getSize().x;
	//return brick.getSize().x;
}

float Brick::height() const
{
	return getSize().y;
	//return brick.getSize().y;
}

float Brick::right() const
{
	return getPosition2().x + width() / 2.f;
}

float Brick::left() const
{
	return getPosition2().x - width() / 2.f;
}

float Brick::top() const
{
	return getPosition2().y - height() / 2.f;
}

float Brick::bottom() const
{
	return getPosition2().y + height() / 2.f;
}

void Brick::setIsDestroyed(bool destroyed)
{
	isDestroyed = destroyed;
}

bool Brick::getIsDestroyed() const
{
	return isDestroyed;
}

void Brick::draw(sf::RenderWindow & Window)
{
	Window.draw(brick);
}

float Brick::getCenterPositionX() const
{
	return brick.getPosition().x;
}

void Brick::setPosition2(float x, float y)
{
	brick.setPosition(x, y);
	setPosition(x, y);
}

sf::Vector2f Brick::getPosition2() const
{
	return getPosition();
}

bool Brick::collision(sf::CircleShape & ball)
{
	///*for (int x = 0; x < bricks.getSize(); ++x)
	//{
	//	for (int y = 0; y < blocks[x].size(); ++y)
	//	{
	//		if (blocks[x][y].collision(ball->getBall()))
	//		{
	//			if (blocks[x][y].getPosition().x > ball->getPosition().x - 25.f && blocks[x][y].getPosition().x < ball->getPosition().x + 25.f) ball->direction.y = -ball->direction.y;
	//			else ball->direction.x = -ball->direction.x;
	//			if (en->playSound) en->click[1].play();
	//			point += 10;
	//			removedBlocks++;
	//			blocks[x].erase(blocks[x].begin() + y);
	//			cout << removedBlocks << endl;
	//		}
	//	}
	//}*/
	if (brick.getGlobalBounds().intersects(ball.getGlobalBounds())) 
		return true;
	else 
		return false;
}

Brick::~Brick()
{

}
