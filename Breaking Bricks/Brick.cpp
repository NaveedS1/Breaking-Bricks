#include "Brick.h"
#include <iostream>

Brick::Brick() 
{

}

Brick::Brick(float outlineThickness, float width, float height)
{
	brick.setFillColor(defColor);
	brick.setOutlineColor(defColorOutLine);
	brick.setSize(sf::Vector2f(width, height));
	brick.setOutlineThickness(outlineThickness);
}

Brick & Brick::operator=(const Brick & oBrick)
{
	this->brick = oBrick.brick;
	this->isDestroyed = oBrick.isDestroyed;
	this->defColor = oBrick.defColor;
	this->defColorOutLine = oBrick.defColorOutLine;

	return *this;
}

void Brick::setPosition(float x, float y)
{
	brick.setPosition(x, y);
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
