#include "Entity.h"

Entity::Entity(unsigned int windowWidth, unsigned int windowHeight)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;

	this->defColor = sf::Color::Green;
	this->velocity = { 0 ,0 };
}

Entity::~Entity()
{
}

void Entity::draw(sf::RenderWindow &window)
{
	window.draw(rectShape);
}

bool Entity::intersects(const Entity &other) const
{
	bool intersected = false;
	if (getPosition().x < other.getPosition().x + other.getSize().x &&
		getPosition().x + getSize().x > other.getPosition().x &&
		getPosition().y < other.getPosition().y + other.getSize().y &&
		getPosition().y + getSize().y > other.getPosition().y)
	{
		intersected = true;
	}
	return intersected;
}

bool Entity::intersectsX(const Entity &other) const
{
	bool intersectedX = false;

	if (getPosition().x < x + width &&
		getPosition().x + getSize().x > x)
	{
		intersectedX = true;
	}
	return intersectedX;
}

bool Entity::intersectsY(const Entity &other) const
{
	bool intersectedY = false;
	if (getPosition().y < y + height &&
		getPosition().y + getSize().y > y)
	{
		intersectedY = true;
	}
	return intersectedY;
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

void Entity::setDefaultVelocity(const float newVelocityX, const float newVelocityY)
{
	this->velocity = sf::Vector2f(newVelocityX, newVelocityY);
}

void Entity::changeVelocityX()
{
	this->velocity.x *= -1;
}

void Entity::changeVelocityY()
{
	this->velocity.y *= -1;
}

sf::Vector2f Entity::getPosition() const
{
	return position;
}

void Entity::setPosition(const float x, const float y)
{
	position = sf::Vector2f(x, y);
}

void Entity::setPositionX(const float x)
{
	position.x = x;
}

void Entity::setPositionY(const float y)
{
	position.y = y;
}

sf::Vector2i Entity::getSize() const
{
	return size;
}

void Entity::setSize(sf::Vector2i newSize)
{
	this->size = newSize;
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
