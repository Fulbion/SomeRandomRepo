#include "Game/Player.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN::WIDTH, SCREEN::HEIGHT), "Elysium");
	window.setFramerateLimit(60);

	Player player;
	player.setPosition(SCREEN::WIDTH / 2, SCREEN::HEIGHT / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (window.hasFocus())
		{
			window.clear();

			player.update();
			player.render(window);

			window.display();
		}
	}
}