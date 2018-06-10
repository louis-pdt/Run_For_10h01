#pragma once
#include "VisibleGameObject.h"
class Ground : public VisibleGameObject
{
public:
	Ground(b2World* World, float X, float Y);
	Ground(pugi::xml_node root, b2World *World);
	void Draw(sf::RenderWindow& rw);

private:

};
