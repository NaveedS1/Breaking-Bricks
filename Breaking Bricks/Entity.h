#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
private:
	sf::RectangleShape rectShape;
	sf::Color defColor;
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::Vector2i size;
	int windowWidth,
		windowHeight;
	float x,
		y, width, height;
public:
	Entity(unsigned int windowWidth = 800, unsigned int windowHeight = 600);
	virtual ~Entity();
	void draw(sf::RenderWindow &window);
	bool intersects(const Entity &other) const;
	//bool intersects(float x, float y, float width, float height) const;
	bool intersectsX(const Entity &other) const;
	//bool intersectsX(float x, float width) const;
	bool intersectsY(const Entity &other) const;
	//bool intersectsY(float y, float height) const;
	sf::Color getDefColor() const;
	void setDefColor(const sf::Color &defColors);
	sf::Vector2f getVelocity() const;
	float getVelocityX() const;
	float getVelocityY() const;
	void setDefaultVelocity(const float newVelocityX, const float newVelocityY);
	void changeVelocityX();
	void changeVelocityY();
	sf::Vector2f getPosition() const;
	void setPosition(const float x, const float y);
	void setPositionX(const float x);
	void setPositionY(const float y);
	sf::Vector2i getSize() const;
	void setSize(sf::Vector2i newSize);
	int getWindowWidth() const;
	int getWindowHeight() const;
};

