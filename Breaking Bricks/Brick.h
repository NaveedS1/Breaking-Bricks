#ifndef BRICK_H
#define BRICK_H

#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Entity.h"
class Brick : public Entity
{
private:
	sf::RectangleShape brick;
	sf::Color defColor{ sf::Color::Yellow };
	sf::Color defColorOutLine{ sf::Color::Green };
	sf::Vector2f position;
	bool isDestroyed;
public:
	Brick();
	Brick(float outlineThickness, float width, float height);
	Brick(const Brick& oBrick) = default;
	Brick& operator=(const Brick& oBricks);

	//void setPosition(const float x, const float y);
	/*float xPosition() const;
	float yPosition() const;*/
	float width() const;
	float height() const;
	float right() const;
	float left() const;
	float top() const;
	float bottom() const;
	
	void setIsDestroyed(bool destroyed);
	bool getIsDestroyed() const;

	void draw(sf::RenderWindow &Window);
	float getCenterPositionX() const;
	void setPosition2(float x, float y);
	sf::Vector2f getPosition2() const;
	bool collision(sf::CircleShape &ball);
	~Brick();
};
#endif // !BRICK_H

