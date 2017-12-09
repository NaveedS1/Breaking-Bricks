#ifndef BRICK_HANDLER_H
#define BRICK_HANDLER_H

#include "Brick.h"
#include "Ball.h"
#include "Resource.h"
#include <SFML\Graphics.hpp>

class BrickHandler {
public:
	BrickHandler(int windowSizeX);
	~BrickHandler();

	const float THICKNESS = 2.f;
	const int WIDTH = 77;
	const int HEIGHT = 15;

	void initializeBricks(int windowSizeX);
	void setBrickPositions();
	void draw(sf::RenderWindow &Window);
	void update(Ball &ball);
	void resetGame();

private:
	Brick *brickList;
	int windowSizeX,
		brickListSize;
	Resource score;

	bool intersectsX(float rectX, int rectW, float ballX, int ballW);
	bool intersectsY(float rectY, int rectH, float ballY, int ballH);
	bool intersects(float rectX, float rectY, int rectW, int rectH, float ballX, float ballY, int ballW, int ballH);
};

#endif // !BRICK_HANDLER_H