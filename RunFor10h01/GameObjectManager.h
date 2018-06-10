#pragma once
#include "VisibleGameObject.h"


/** Classe qui contient les objets visibles du jeu, et qui permet de les dessiner et les mettre a jour */
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