#pragma once
#include <SFML/Graphics.hpp>

#define MAX_ITEMS 16

class coolMenu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_ITEMS];

	sf::Texture texture;
	sf::Sprite background;

public:
	coolMenu(float width, float height)
	{
		font.loadFromFile("./arial.ttf");

		texture.loadFromFile("./Texture.png");
		background.setTexture(texture);
		background.setPosition(0, 150);

		text[0].setFont(font);
		text[0].setFillColor(sf::Color::Cyan);
		text[0].setString("Run All Tasks");
		text[0].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 1));

		// Task 1
		text[1].setFont(font);
		text[1].setFillColor(sf::Color::White);
		text[1].setString("Number of Nodes");
		text[1].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 2));

		// Task 2
		text[2].setFont(font);
		text[2].setFillColor(sf::Color::White);
		text[2].setString("Number of Edges");
		text[2].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 3));

		// Task 3
		text[3].setFont(font);
		text[3].setFillColor(sf::Color::White);
		text[3].setString("Number of Source Nodes");
		text[3].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 4));

		// Task 4
		text[4].setFont(font);
		text[4].setFillColor(sf::Color::White);
		text[4].setString("Number of Sink Nodes");
		text[4].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 5));

		// Task 5
		text[5].setFont(font);
		text[5].setFillColor(sf::Color::White);
		text[5].setString("Number of Isolated Nodes");
		text[5].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 6));

		// Task 6
		text[6].setFont(font);
		text[6].setFillColor(sf::Color::White);
		text[6].setString("Number of Bridge Edges");
		text[6].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 7));

		// Task 7
		text[7].setFont(font);
		text[7].setFillColor(sf::Color::White);
		text[7].setString("Number of Articulation Nodes");
		text[7].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 8));

		// Task 8
		text[8].setFont(font);
		text[8].setFillColor(sf::Color::White);
		text[8].setString("Shortest Path Length Distribution*");
		text[8].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

		// Task 9
		text[9].setFont(font);
		text[9].setFillColor(sf::Color::White);
		text[9].setString("Diameter");
		text[9].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

		// Task 10
		text[10].setFont(font);
		text[10].setFillColor(sf::Color::White);
		text[10].setString("In-Degree Distribution*");
		text[10].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

		// Task 11
		text[11].setFont(font);
		text[11].setFillColor(sf::Color::White);
		text[11].setString("Out-Degree Distribution*");
		text[11].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 4));

		// Task 12
		text[12].setFont(font);
		text[12].setFillColor(sf::Color::White);
		text[12].setString("Size of Largest SCC");
		text[12].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 5));

		// Task 13
		text[13].setFont(font);
		text[13].setFillColor(sf::Color::White);
		text[13].setString("SCC Distribution*");
		text[13].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 6));

		// Task 14
		text[14].setFont(font);
		text[14].setFillColor(sf::Color::White);
		text[14].setString("Size of Largest WCC");
		text[14].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 7));

		// Task 15
		text[15].setFont(font);
		text[15].setFillColor(sf::Color::White);
		text[15].setString("WCC Distribution*");
		text[15].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 8));

		selectedItemIndex = 0;
	}
	~coolMenu() {};

	void draw(sf::RenderWindow& window)
	{
		window.draw(background);

		for (int i = 0; i < MAX_ITEMS; i++)
			window.draw(text[i]);
	}
	void MoveUp()
	{
		if (selectedItemIndex - 1 >= 0)
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			text[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}
	void MoveDown()
	{
		if (selectedItemIndex + 1 < MAX_ITEMS)
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			text[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}
	int GetPressedItem() 
	{ 
		return selectedItemIndex; 
	}
};