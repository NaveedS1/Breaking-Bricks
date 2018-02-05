#ifndef BRICK_HANDLER_H
#define BRICK_HANDLER_H

#include "Brick.h"
#include "Ball.h"
#include "Resource.h"
#include "Entity.h"
#include "SoundEffects.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class BrickHandler 
{
private:
	Brick *brickList;
	int windowSizeX;
	int brickListSize;
	Resource *score;
	SoundEffects *sound;
public:
	BrickHandler(int windowSizeX, Resource &score, SoundEffects &sound);
	~BrickHandler();

	const float THICKNESS = 2.f;
	const int WIDTH = 77;
	const int HEIGHT = 15;

	void initializeBricks(int windowSizeX);
	void setBrickPositions();
	void draw(sf::RenderWindow &Window);
	void update(Entity &entity);
	void resetGame();

};

#endif // !BRICK_HANDLER_H