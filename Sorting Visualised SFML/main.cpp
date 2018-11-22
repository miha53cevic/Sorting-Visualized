#include "game.h"
#include <iostream>
int main()
{
	int choice;
	std::cout << "1. BubbleSort\n2. SelectionSort\nOdabir: ";
	std::cin >> choice;

	char c;
	std::cout << "\n\nSpeed limit y/n\nChoice: ";
	std::cin >> c;

	Game game(sf::Vector2u(1280, 720), "Sorting Visualised");

	if (c == 'n') game.getWindow()->getWindow()->setFramerateLimit(0);

	while (!game.getWindow() -> IsDone())
	{
		if (game.HandleInput())
			if (choice == 1) game.getSortManager()->BubbleSort();
			else game.getSortManager()->SelectionSort();

		game.Update();
		game.Render();
		game.RestartClock();
	}

	return 0;
}