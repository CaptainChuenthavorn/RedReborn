#include <sfml\Graphics.hpp>
#include "window.h"
#include "Game.h"
int main()
{
	Game game;//create game class valiable
	while (!game.getWindow()->IsDone())
	{
		//game.HandleInput();
		game.Update();
		game.Render();
	}

	return 0;
}

