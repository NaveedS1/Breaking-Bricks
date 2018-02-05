#ifndef BALL_H
#define BALL_H
#include <iostream>

#include <SFML\Graphics.hpp>
#include "Paddle.h"
#include "Entity.h"

class Ball : public Entity
{
private:
	sf::CircleShape ball;

	const float ballRadius = 12.0f;
	const float defaultVelocity = 0.30f; //0.19
public:
	Ball();
	Ball(unsigned int windowWidth, unsigned int windowHieght);
	void createBall();
	~Ball() { };

	//! Updating the ball
	/*! Will return false if the player miss the ball with the paddle. */
	bool update(Paddle &paddle);

	float right(); 
	float left(); 
	float bottom(); 
	float top(); 
	float getCirclePositionX(); 
	float getCircleRadius();

	void draw(sf::RenderWindow &Window);
	void moveBall();

	float getRadius() const;
	bool testBottomCollision();

	void reset();

};
#endif // !BALL_H

