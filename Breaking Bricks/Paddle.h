#ifndef PADDLE_H
#define PADDLE_H

#include <SFML\Graphics.hpp>
#include "Entity.h"

class Paddle : public Entity
{
public:
	Paddle(/*float startX, float startY*/);
	
	void draw(sf::RenderWindow &Window);
	void update();

	float getPositionEDGERIGHTX();
	float getPositionEDGETOPY();
	float getPositionEDGELEFTX();
	float getPositionEDGEDOWNY();
	float getCenterPositionX() { return rect.getPosition().x; }
	float getRectWidth() { return rectWidth; }
	float getRectHeight() { return rectHeight; }
	float getX() const { return rect.getPosition().x; }
	float getY() const { return rect.getPosition().y; }
	void setPosition(float x, float y);
	bool isWithinBounds();
	bool goRight();
	bool goLeft();

	~Paddle(); 

private:
	sf::RectangleShape rect;
	//sf::Color defColorRectFill{ sf::Color::White };
	//const int windowWidth{ 800 }, windowHeight{ 600 };
	float rectWidth = 100.f;
	float rectHeight = 14.f;
	float rectVelocity = .45f;// 0.34


	float DTPositionX = 5.0f;
	float DTPositionY = 0.0f;

	float DTMoveX = 16.0f;
	float DTMoveY = 0.0;

	void paddleMovementLiveInput();

	sf::Vector2f postion{ DTPositionX, DTPositionY };
	sf::Vector2f move{ DTMoveX, DTMoveY };
	//sf::Vector2f velocity;
};
#endif // !PADDLE_H

