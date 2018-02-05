#include "Ball.h"

Ball::Ball()
{
	createBall();
}

Ball::Ball(unsigned int windowWidth, unsigned int windowHeight) : Entity(windowWidth, windowHeight)
{
	createBall();
}

void Ball::createBall()
{
	ball.setRadius(ballRadius);
	setSize(sf::Vector2<int>(ballRadius * 2, ballRadius * 2));
	setDefColor(sf::Color::Green);
	reset();
}

bool Ball::update(Paddle &paddle)
{
	bool playerSurvive = true;
	/*circle.move(postion);
	sloveBoundCollisions();*/

	// check if ball hits the paddle
	if (ball.getPosition().x > paddle.getPosition().x
		&& ball.getPosition().x + this->getRadius() < paddle.getPosition().x + paddle.getRectWidth()
		&& ball.getPosition().y + this->getRadius() * 2 > paddle.getPosition().y)
	{
		changeVelocityY(); // redirect balls velocity y by *-1
	}
	else if (this->bottom() > getWindowHeight()) // player did not hit paddle and lost
	{
		playerSurvive = false;
	}
	else if (top() < 0)
	{
		changeVelocityY();
	}
	else if (bottom() > getWindowHeight())
	{
		changeVelocityY();
	}
	
	if (left() < 0)
	{
		changeVelocityX();
	}
	else if (right() > getWindowWidth())
	{
		changeVelocityX();
	}

	moveBall();
	
	return playerSurvive;
}

void Ball::moveBall()
{
	ball.setPosition(ball.getPosition().x + getVelocityX(), ball.getPosition().y + getVelocityY());

	setPosition(ball.getPosition().x, ball.getPosition().y);
}

float Ball::right()
{
	return ball.getPosition().x + getRadius() * 2;
}

float Ball::left()
{
	return ball.getPosition().x;
}

float Ball::bottom()
{
	return ball.getPosition().y + getRadius() * 2;
}

float Ball::top()
{
	return ball.getPosition().y;
}

float Ball::getCirclePositionX()
{
	return ball.getPosition().x;
}

float Ball::getCircleRadius()
{
	return getRadius();
}

void Ball::draw(sf::RenderWindow & window)
{
	window.draw(ball);
}

float Ball::getRadius() const
{
	return ballRadius;
}

bool Ball::testBottomCollision()
{
	if (ball.getPosition().y >= getWindowWidth() - ballRadius)
		return true;
	else
		return false;
}

void Ball::reset()
{
	ball.setPosition(getWindowWidth() / 2 - getRadius(), getWindowHeight() - getRadius() - 100);
	setPosition(ball.getPosition().x, ball.getPosition().y);
	setDefaultVelocity(-defaultVelocity, -defaultVelocity);
}
