#include "Header.h"
#include<SFML/Graphics.hpp>
#include "Menu.h"
int main()
{
	string dataPath = "./Text.txt";
	graph G1;
	G1.createGraph(dataPath);

	sf::RenderWindow window(sf::VideoMode(960, 720), "Network Analysis Using Graphs");

	coolMenu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						break;
					case 1:
						G1.numberOfNodes();
						break;
					case 2:
						G1.numberOfEdges();
						break;
					case 3:
						G1.numberOfSourceNodes();
						break;
					case 4:
						G1.numberOfSinkNodes();
						break;
					case 5:
						G1.numberOfIsolatedNodes();
						break;
					case 6:
						break;
					case 7:
						G1.noOfArticulationNodes();
						break;
					case 8:
						break;
					case 9:
						break;
					case 10:
						G1.displayInDegree();
						break;
					case 11:
						G1.displayOutDegree();
						break;
					case 12:
						G1.findLargestSCC();
						break;
					case 13:
						break;
					case 14:
						G1.findLargestWCC();
						break;
					case 15:
						break;
					}
					break;
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
}