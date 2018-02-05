#ifndef PADDLE_H
#define PADDLE_H

#include <SFML\Graphics.hpp>
#include "Entity.h"

class Paddle : public Entity
{
private:
	sf::RectangleShape rect;
	//sf::Color defColorRectFill{ sf::Color::White };
	//const int windowWidth{ 800 }, windowHeight{ 600 };
	float rectWidth = 100.f;
	float rectHeight = 14.f;
	float paddleSpeed = .45f; // 0.34

	float DTPositionX = 5.0f;
	float DTPositionY = 0.0f;

	float DTMoveX = 16.0f;
	float DTMoveY = 0.0;

	void paddleMovementLiveInput();

	sf::Vector2f move{ DTMoveX, DTMoveY };
public:
	Paddle();
	Paddle(unsigned int windowWidth, unsigned int windowHeight);
	void createPaddle();
	
	void draw(sf::RenderWindow &Window);
	void update();

	float getPositionEDGERIGHTX();
	float getPositionEDGETOPY();
	float getPositionEDGELEFTX();
	float getPositionEDGEDOWNY();
	float getCenterPositionX();
	float getRectWidth();
	float getRectHeight();
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	bool isWithinBounds();
	bool goRight();
	bool goLeft();

	void reset();

	~Paddle(); 
};
#endif // !PADDLE_H

