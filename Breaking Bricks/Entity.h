#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
private:
	sf::Color defColor;
	sf::Vector2f velocity;
	const int windowWidth = 800, windowHeight = 600;
public:
	Entity();
	virtual ~Entity();

	sf::Color getDefColor() const;
	void setDefColor(const sf::Color &defColors);
	sf::Vector2f getVelocity() const;
	void addVelocity(const sf::Vector2f newVelocity);
	void setVelocity(const sf::Vector2f newVelocity);
	void setVelocityX(float x);
	void setVelocityY(float y);
	float getVelocityX() const;
	float getVelocityY() const;
	int getWindowWidth() const;
	int getWindowHeight() const;
};

