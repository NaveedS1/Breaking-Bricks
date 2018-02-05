#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameEngine.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameEngine game;

	game.run();

	//system("pause");
	return 0;
}