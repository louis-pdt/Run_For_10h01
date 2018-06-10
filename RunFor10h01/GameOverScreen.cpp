#include "StdAfx.h"
#include "GameOverScreen.h"


void GameOverScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("../RunFor10h01/images/GameOver.png") != true)
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