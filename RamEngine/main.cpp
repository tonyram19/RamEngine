#include "Game.h"

int main()
{
	
	Game game;

	game.Initialize("Test Game", 60, 1000, 1000);

	while (game.IsRunning())
	{

		game.Update();
		game.Draw();
	}

	return 0;
}