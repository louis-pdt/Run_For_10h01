#pragma once
#include "VisibleGameObject.h"



class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(VisibleGameObject* gameObject);
	int GetObjectCount() const;
	
	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();

	void RemoveAll();

private:
	std::vector<VisibleGameObject*> _gameObjects;
	
	sf::Clock clock;
};