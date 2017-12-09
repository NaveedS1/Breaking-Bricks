#ifndef BRICK_H
#define BRICK_H

#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Entity.h"
class Brick : public Entity
{
public:
	Brick();
	Brick(float outlineThickness, float width, float height);
	Brick(const Brick& oBrick) = default;
	Brick& operator=(const Brick& oBricks);

	float xPosition() { return brick.getPosition().x; }
	float yPosition() { return brick.getPosition().y; }
	float width() { return brick.getSize().x; }
	float height() { return brick.getSize().y; }
	float right() { return xPosition() + width() / 2.f; }
	float left() { return xPosition() - width() / 2.f; }
	float top() { return yPosition() - height() / 2.f; }
	float bottom() { return yPosition() + height() / 2.f; }
	
	bool isDestroyed = false;

	void draw(sf::RenderWindow &Window) { Window.draw(brick); }
	float getCenterPositionX() { return brick.getPosition().x; }
	void setPosition(float x, float y);
	bool collision(sf::CircleShape &ball);
	~Brick();
private:
	sf::RectangleShape brick;
	sf::Color defColor{ sf::Color::Yellow };
	sf::Color defColorOutLine{ sf::Color::Green };
};
#endif // !BRICK_H

