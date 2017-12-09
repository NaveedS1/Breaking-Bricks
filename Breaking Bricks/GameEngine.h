#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "BrickHandler.h"
#include "Resource.h"

class GameEngine
{
private:
	
	Ball ball; 
	Paddle paddle;
	Resource score;
public:
	GameEngine();
	~GameEngine();
	
	void run();
	void canPaddleMove(float rectVelocity);
	
	void upadteWindow(sf::RenderWindow &window, float rectVelocity);

};

#endif // !GAMEENGINE_H
