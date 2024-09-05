#include <iostream>
#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	while (game.running() && !game.getEndGame())
	{
		game.update();
		game.render();
	}
	std::cout << "you lost buddy u trash" << '\n';



	return 0;
}

