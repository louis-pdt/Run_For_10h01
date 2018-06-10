#include "stdafx.h"
#include "PauseMenu.h"
#include <iostream>


PauseMenu::MenuResult PauseMenu::Show(sf::RenderWindow& window)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("../RunFor10h01/images/PauseMenu.png");
	sf::Sprite sprite(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem continueButton;
	continueButton.rect.top = 150;
	continueButton.rect.height = 290 - 150;
	continueButton.rect.left = 0;
	continueButton.rect.width = 1920;
	continueButton.action = Continue;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1920;
	exitButton.rect.top = 630;
	exitButton.rect.height = 790 - 630;
	exitButton.action = Exit;

	MenuItem TryAgainButton;
	TryAgainButton.rect.left = 0;
	TryAgainButton.rect.width = 1920;
	TryAgainButton.rect.top = 390;
	TryAgainButton.rect.height = 560 - 390;
	TryAgainButton.action = TryAgain;

	_menuItems.push_back(continueButton);
	_menuItems.push_back(exitButton);
	_menuItems.push_back(TryAgainButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

PauseMenu::MenuResult PauseMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.height + menuItemRect.top > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.width > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}

PauseMenu::MenuResult  PauseMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (window.pollEvent(menuEvent))
	{
		std::cout << "x : " << sf::Mouse::getPosition().x << "  y : " << sf::Mouse::getPosition().y << std::endl;
		if (menuEvent.type == sf::Event::MouseButtonPressed)
		{
			return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
		}
		if (menuEvent.type == sf::Event::Closed)
		{
			return Exit;
		}
	}
}