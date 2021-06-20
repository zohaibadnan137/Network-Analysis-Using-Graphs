#pragma once
#include <SFML/Graphics.hpp>

#define MAX_ITEMS 7

class CoolMenu
{
public:
	CoolMenu(float width, float height)
	{
		if (!font.loadFromFile("./arial.ttf"))
		{
			// Handle error
		}

		if (!texture.loadFromFile("./Texture.png"))
		{
			// Texture error
		}

		background.setTexture(texture);
		background.setPosition(0, 150);

		text[0].setFont(font);
		text[0].setFillColor(sf::Color::Cyan);
		text[0].setString("Run All Tasks");
		text[0].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 0.5));

		text[1].setFont(font);
		text[1].setFillColor(sf::Color::White);
		text[1].setString("Number of Nodes");
		text[1].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 1));

		text[2].setFont(font);
		text[2].setFillColor(sf::Color::White);
		text[2].setString("Number of Edges");
		text[2].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 1.5));

		text[3].setFont(font);
		text[3].setFillColor(sf::Color::White);
		text[3].setString("Number of Source Nodes");
		text[3].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 2));

		text[4].setFont(font);
		text[4].setFillColor(sf::Color::White);
		text[4].setString("Number of Sink Nodes");
		text[4].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 2.5));

		text[5].setFont(font);
		text[5].setFillColor(sf::Color::White);
		text[5].setString("Number of Isolated Nodes");
		text[5].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 3));

		text[6].setFont(font);
		text[6].setFillColor(sf::Color::White);
		text[6].setString("Number of Articulation Nodes");
		text[6].setPosition(sf::Vector2f(width / 15, height / (MAX_ITEMS + 1) * 3.5));
	}
	~CoolMenu()
	{

	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(background);
		for (int count = 0; count < MAX_ITEMS; count++)
			window.draw(text[count]);
	}
	void moveUp()
	{

	}
	void moveDown()
	{

	}

private:
	//int selectedItem;
	sf::Font font;
	sf::Text text[MAX_ITEMS];

	sf::Texture texture;
	sf::Sprite background;
};