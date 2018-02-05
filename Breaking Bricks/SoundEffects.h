#pragma once
#include <SFML\Audio.hpp>
#include <iostream>
#include <fstream>

class SoundEffects
{
private:
	sf::SoundBuffer buffer1;
	sf::Sound sound;
public:
	SoundEffects();
	~SoundEffects();

	void playBounceBallSound();
};

