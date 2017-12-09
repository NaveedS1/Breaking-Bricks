#include "Ball.h"

Ball::Ball()
{ 
	ball.setPosition(startX, startY);
	ball.setRadius(ballRadius);
	setDefColor(sf::Color::Green);
	setVelocity(sf::Vector2f { -ballVelocity, -ballVelocity });
}

Ball::~Ball()
{
}

bool Ball::update(Paddle &paddle)
{
	bool playerSurvive = true;
	/*circle.move(postion);
	sloveBoundCollisions();*/

	// check if ball hits the paddle
	if (this->x() > paddle.getX()
		&& this->x() + this->getRadius() < paddle.getX() + paddle.getRectWidth()
		&& this->y() + this->getRadius() * 2 > paddle.getY())
	{
		setVelocityY(getVelocityY() * -1); // redirect balls velocity y by *-1
	}
	else if (this->bottom() > getWindowHeight()) // player did not hit paddle and lost
	{
		playerSurvive = false;
	}

	ball.move(getVelocity());
	
	if (left() < 0)
	{
		setVelocityX(ballVelocity);
	}
	else if (right() > getWindowWidth())
	{
		setVelocityX(-ballVelocity);
	}
	if (top() < 0)
	{
		setVelocityY(ballVelocity);
	}
	else if (bottom() > getWindowHeight())
	{
		setVelocityY(-ballVelocity);
	}

	return playerSurvive;
}

float Ball::x()
{
	return ball.getPosition().x; 
}

float Ball::y()
{
	return ball.getPosition().y;
}

float Ball::right()
{
	return x() + getRadius() * 2;
}

float Ball::left()
{
	return x();
}

float Ball::bottom()
{
	return y() + getRadius() * 2;
}

float Ball::top()
{
	return y();
}

float Ball::getCirclePositionX()
{
	return ball.getPosition().x;
}

float Ball::getCircleRadius()
{
	return getRadius();
}

sf::CircleShape Ball::getBall()
{
	 return ball;
}

void Ball::draw(sf::RenderWindow & Window)
{
	Window.draw(ball);
}

void Ball::setPosition(float x, float y)
{
	ball.setPosition(x, y);
}

float Ball::getRadius() const
{
	return ballRadius;
}

bool Ball::testBottomCollision(Ball & mBall)
{
	if (mBall.y() >= getWindowWidth() - ballRadius)
		return true;
	else
		return false;
}

float Ball::getBallVelocity()
{
	return ballVelocity;
}

