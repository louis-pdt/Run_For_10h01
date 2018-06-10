#pragma once
#include "VisibleGameObject.h"
class Player : public VisibleGameObject
{
public :
	Player(b2World* World, float X, float Y);
	Player(pugi::xml_node root, b2World* World);
	void Jump();
	void Update();
	void Draw(sf::RenderWindow& rw);

	//std::string GetObjectType() const;

private :
	int stepsSinceLastJump;
	static const int maxLatVel = 5;
};
