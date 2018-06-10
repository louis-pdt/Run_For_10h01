#pragma once
#include "VisibleGameObject.h"

class ObstacleBas : public VisibleGameObject
{
public:
	ObstacleBas(b2World* World, float X, float Y);
	~ObstacleBas();

	void Draw(sf::RenderWindow& rw);

private:

};

