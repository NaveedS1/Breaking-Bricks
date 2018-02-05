#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "BrickHandler.h"
#include "Resource.h"
#include "SoundEffects.h"

class GameEngine
{
private:
	int highScore[10];
	Ball ball; 
	Paddle paddle;
	Resource score;
	SoundEffects sound;
public:
	GameEngine();
	~GameEngine();
	
	void run();
	
	void upadteWindow(sf::RenderWindow &window, float rectVelocity);

};

#endif // !GAMEENGINE_H
