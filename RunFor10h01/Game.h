#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

#include <iostream>
#include "b2GLDraw.h"

#include "GameObjectManager.h"
#include "Player.h"
#include "Obstacle.h"
#include "Ground.h"

#include "MainMenu.h"
#include "h1001Screen.h"
#include "PauseMenu.h"
#include "GameOverScreen.h"

class Game
{
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static int SCREEN_WIDTH = 1920;
	const static int SCREEN_HEIGHT = 1080;
	const static int FPS = 60.f;
	const static GameObjectManager & GetGameObjectManager();


private:
	static bool IsExiting();
	static void GameLoop();

	static void Showh1001Screen();
	static void ShowMenu();
	static void ShowPauseMenu();

	static void ObstacleGenerator(float secondes);

	static void GameOverTest();

	enum GameState {
		Uninitialized, ShowingRunFor10h01, Paused,
		ShowingMenu, Playing, Exiting, GameOver
	};
	enum GameObstacle{Haut, Bas};

	static int nbrObstacles;
	static int nbrMaxObstacles;

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;

	static sf::Clock clock;

	static b2World* myWorld;
};


