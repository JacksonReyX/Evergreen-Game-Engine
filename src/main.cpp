#include "Game/game.h"
//#import "raylib.h"
#include "raylib-cpp.hpp"

int main(int argc, char* argv[])
{
	//in game have a boolean switching between editor mode and game mode
	Game game;

	game.initialize();

	game.run();

	game.destroy();

	return 0;
}
