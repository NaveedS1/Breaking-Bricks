#include "BrickHandler.h"

BrickHandler::BrickHandler(int windowSizeX) : windowSizeX(windowSizeX) {
	initializeBricks(windowSizeX);
}

void BrickHandler::initializeBricks(int windowSizeX) {
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

void BrickHandler::setBrickPositions() {
	int offsetX = (/*(*/windowSizeX /*- (windowSizeX / WIDTH) * brickMargin)*/ % WIDTH) / 2 + 1; // offset x in pixels
	int offsetY = offsetX; // offset y in pixels

	// loop through the list and set correct positions
	int i = 0;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < windowSizeX / WIDTH; x++) {
			brickList[i].isDestroyed = false;
			brickList[i++].setPosition(x * WIDTH /*+ x * THICKNESS*/ + offsetX, y * HEIGHT + /*y * THICKNESS*/ + offsetY);
		}
	}
}

void BrickHandler::draw(sf::RenderWindow &window) {
	for (int i = 0; i < brickListSize; i++)
	{
		if (!brickList[i].isDestroyed)
		{
			brickList[i].draw(window);
		}
	}
}

void BrickHandler::update(Ball &ball) {
	for (int i = 0; i < brickListSize; i++)
	{
		if (!brickList[i].isDestroyed)
		{
			// confirm it intersects...
			if (intersects(brickList[i].xPosition(), brickList[i].yPosition(), WIDTH, HEIGHT, ball.x(), ball.y(), ball.getRadius(), ball.getRadius()))
			{
				// check whether Y intersect
				if (intersectsY(brickList[i].yPosition(), HEIGHT, ball.y(), ball.getRadius()))
				{
					ball.setVelocityY(ball.getVelocityY() * -1);
				}

				// check whether X intersect
				if (intersectsX(brickList[i].xPosition(), WIDTH, ball.x(), ball.getRadius())
					&& !(WIDTH - (WIDTH / 10) + (WIDTH / 5)))
				{
					ball.setVelocityX(ball.getVelocityX() * -1);
				}

				// set destroyed and then break the for-loop
				score.updateScore(50);
				brickList[i].isDestroyed = true;
				break;
			}
		}
	}
}

void BrickHandler::resetGame()
{
	setBrickPositions();
}

bool BrickHandler::intersects(float rectX, float rectY, int rectW, int rectH, float ballX, float ballY, int ballW, int ballH) {
	return ballX < rectX + rectW &&
		ballX + ballW > rectX &&
		ballY < rectY + rectH &&
		ballY + ballH > rectY;
	
}

bool BrickHandler::intersectsX(float rectX, int rectW, float ballX, int ballW) {
	return ballX < rectX + rectW &&
 		ballX + ballW > rectX;
}

bool BrickHandler::intersectsY(float rectY, int rectH, float ballY, int ballH) {
	return ballY < rectY + rectH &&
		ballY + ballH > rectY;
}

BrickHandler::~BrickHandler() {
	delete[] this->brickList;
}