#include "Entity.h"

Entity::Entity()
{
	this->defColor = sf::Color::Green;
	sf::Vector2f velocity = { 0 ,0 };
}

Entity::~Entity()
{
}

sf::Color Entity::getDefColor() const
{
	return this->defColor;
}

void Entity::setDefColor(const sf::Color &defColors)
{
	this->defColor = defColors;
}

sf::Vector2f Entity::getVelocity() const
{
	return this->velocity;
}

void Entity::addVelocity(const sf::Vector2f newVelocity)
{
	this->velocity += newVelocity;
}

void Entity::setVelocity(const sf::Vector2f newVelocity)
{
	this->velocity = newVelocity;
}

void Entity::setVelocityX(float x)
{
	this->velocity.x = x;
}

void Entity::setVelocityY(float y)
{
	this->velocity.y = y;
}

float Entity::getVelocityX() const {
	return this->velocity.x;
}

float Entity::getVelocityY() const {
	return this->velocity.y;
}

int Entity::getWindowWidth() const
{
	return this->windowWidth;
}

int Entity::getWindowHeight() const
{
	return this->windowHeight;
}
