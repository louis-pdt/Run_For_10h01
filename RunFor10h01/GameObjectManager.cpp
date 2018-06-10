#include "stdafx.h"
#include "GameObjectManager.h"


GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Add(VisibleGameObject* gameObject)
{

	_gameObjects.push_back(gameObject);
}



int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{

	for(auto it : _gameObjects)
	{
		it->Draw(renderWindow);
		it++;
	}
}

void GameObjectManager::UpdateAll()
{
	float timeDelta = clock.restart().asSeconds();
	
	for (auto it : _gameObjects)
	{
		it->Update();
	}
}

void GameObjectManager::RemoveAll() {
	while(_gameObjects.size() != 0){
		_gameObjects[_gameObjects.size() - 1]->~VisibleGameObject();
		_gameObjects.pop_back();
	}
}
