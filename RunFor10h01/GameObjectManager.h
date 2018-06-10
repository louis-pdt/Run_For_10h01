#pragma once
#include "VisibleGameObject.h"



class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	int GetObjectCount() const;
	
	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();
	VisibleGameObject* Get(std::string name) const;

	void RemoveAll();

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;
	
	sf::Clock clock;
};