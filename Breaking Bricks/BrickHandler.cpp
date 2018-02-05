#include "BrickHandler.h"

BrickHandler::BrickHandler(int windowSizeX, Resource &score, SoundEffects &sound) 
	: windowSizeX(windowSizeX), score(&score), sound(&sound)
{
	initializeBricks(windowSizeX);
}

void BrickHandler::initializeBricks(int windowSizeX) 
{
	const int brickMargin = 2; // pixels between the bricks

	// calculate list size
	brickListSize = HEIGHT * (windowSizeX / WIDTH);
	brickList = new Brick[brickListSize];

	// initialize bricks...
	for (int i = 0; i < brickListSize; i++) {
		brickList[i] = Brick(THICKNESS, WIDTH, HEIGHT);
	}

	setBrickPositions();
}

void BrickHandler::setBrickPositions() 
{
	int offsetX = (/*(*/windowSizeX /*- (windowSizeX / WIDTH) * brickMargin)*/ % WIDTH) / 2 + 1; // offset x in pixels
	int offsetY = offsetX; // offset y in pixels

	// loop through the list and set correct positions
	int i = 0;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < windowSizeX / WIDTH; x++) {
			brickList[i].setIsDestroyed(false);
			
			brickList[i++].setPosition2(x * WIDTH /*+ x * THICKNESS*/ + offsetX, y * HEIGHT + /*y * THICKNESS*/ + offsetY);
		}
	}
}

void BrickHandler::draw(sf::RenderWindow &window) 
{
	for (int i = 0; i < brickListSize; i++)
	{
		if (!brickList[i].getIsDestroyed())
		{
			brickList[i].draw(window);
		}
	}
}

void BrickHandler::update(Entity &entity)
{
	for (int i = 0; i < brickListSize; i++)
	{
		if (!brickList[i].getIsDestroyed())
		{
			if (entity.intersects(brickList[i]))
			{
				if (entity.getPosition().x < brickList[i].getPosition().x + brickList[i].width()
					&& entity.getPosition().x + entity.getSize().x >= brickList[i].getPosition().x)
				{
					entity.changeVelocityX();
				}
					
				if (entity.getPosition().y < brickList[i].getPosition().y + brickList[i].height()
					&& entity.getPosition().y + entity.getSize().y >= brickList[i].getPosition().y)
				{
					entity.changeVelocityY();
				}

				// set destroyed and then break the for-loop
				brickList[i].setIsDestroyed(true);
				score->addScore(10);
				sound->playBounceBallSound();

				i = 0; // continue
			}
		}
	}
}

void BrickHandler::resetGame()
{
	setBrickPositions();
}

BrickHandler::~BrickHandler() {
	delete[] this->brickList;
	// delete[] this->score;
	delete[] this->sound;
}