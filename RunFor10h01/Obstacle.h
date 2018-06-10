#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"

class Obstacle : public VisibleGameObject
{
public:
	Obstacle(b2World* World, float X, float Y);
	Obstacle(pugi::xml_node root, b2World* World);
	~Obstacle();
	void Draw(sf::RenderWindow & rw);
	void Update();
};
