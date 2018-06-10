#include "StdAfx.h"
#include "h1001Screen.h"


void h1001Screen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("../RunFor10h01/images/StartScreen2.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}