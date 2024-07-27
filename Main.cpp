#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>
#include <ctime>
int main() {

	///Initialize a Random Seed
	srand(static_cast<unsigned>(time(0)));


	///Init
	Game game;
	sf::Clock ck;
	
	///Game Loop
	while (game.running()) {
		
		game.update(ck.restart().asSeconds());
		game.render();
	}


	///End of Application
	return 0;

}