#include "SoundEffects.h"

SoundEffects::SoundEffects()
{
	if (!buffer1.loadFromFile("../Resource/bounce.wav"))
	{
		std::cout << " Error load sound effect 1\n";
	}
}

SoundEffects::~SoundEffects()
{
}

void SoundEffects::playBounceBallSound()
{
	sound.setBuffer(buffer1);
	sound.play();
}
