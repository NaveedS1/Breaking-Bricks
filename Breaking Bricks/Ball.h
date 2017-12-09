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
	float startX;
	float startY;

	const float ballRadius = 12.0f;
	const float ballVelocity = .30f; //0.19
public:
	Ball();
	~Ball();

	//! Updating the ball
	/*! Will return false if the player miss the ball with the paddle. */
	bool update(Paddle &paddle);
	
	float x();
	float y(); 
	float right(); 
	float left(); 
	float bottom(); 
	float top(); 
	float getCirclePositionX(); 
	float getCircleRadius(); 
	sf::CircleShape getBall(); 

	void draw(sf::RenderWindow &Window); 

	void setPosition(float x, float y);
	//void setVelocityX(float x);
	//void setVelocityY(float y);
	//float getVelocityX() const;
	//float getVelocityY() const;

	float getRadius() const;
	bool testBottomCollision(Ball& mBall);

	float getBallVelocity();


};
#endif // !BALL_H

