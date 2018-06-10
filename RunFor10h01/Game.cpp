#include "stdafx.h"
#include "Game.h"
#include <vector>


void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Run for 10h01");
	
	b2Vec2 gravity(0, 10.f); //normal earth gravity, 9.8 m/s/s straight down!
	myWorld = new b2World(gravity);

	pugi::xml_document doc;
	doc.load_file("../RunFor10h01/sourceXML/Player.xml");
	pugi::xml_node root = doc.child("VisibleGameObject");
	Player* player1 = new Player(root, myWorld);

	doc.load_file("../RunFor10h01/sourceXML/Ground.xml");
	root = doc.child("VisibleGameObject");
	Ground* ground = new Ground(root, myWorld);

	_gameObjectManager.Add(player1);
	_gameObjectManager.Add(ground);

	srand((int)time(NULL));//initialisation de random pour la generation aleatoire d obstacles
	nbrObstacles = 15; //on commence avec 15 obstacles
	clock;

	//initialisation debugger graphique box2d
	b2GLDraw debugDrawInstance;
	myWorld->SetDebugDraw(&debugDrawInstance);
	uint32 flags = 0;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_centerOfMassBit;
	debugDrawInstance.SetFlags(flags);

	clock.restart();
	_gameState = Game::ShowingRunFor10h01;



	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}


sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);


	switch (_gameState)
	{
	case Game::ShowingMenu:
	{
		ShowMenu();
		break;
	}
	case Game::Paused:
	{
		ShowPauseMenu();
		break;
	}
	case Game::ShowingRunFor10h01:
	{
		Showh1001Screen();
		break;
	}
	case Game::Playing:
	{
		double start = clock.getElapsedTime().asMilliseconds();

		_mainWindow.clear(sf::Color::White);
		myWorld->Step(1/60.f, 8, 3);

		_gameObjectManager.UpdateAll();
		ObstacleGenerator(clock.getElapsedTime().asSeconds());
		//_gameObjectManager.DrawAll(_mainWindow);

		myWorld->DrawDebugData();
		_mainWindow.display();

		if (currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape) _gameState = Game::Paused;

		}
		//std::cout << (1000 / FPS - clock.getElapsedTime().asMilliseconds() + start) << std::endl;
		Sleep(1000/FPS - clock.getElapsedTime().asMilliseconds() + start);
		break;
	}
	}
}

void Game::Showh1001Screen()
{
	h1001Screen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Exiting;
		break;
	case MainMenu::Play:
		_gameState = Playing;
		break;
	}
}

void Game::ShowPauseMenu()
{
	PauseMenu PauseMenu;
	PauseMenu::MenuResult result = PauseMenu.Show(_mainWindow);
	switch (result)
	{
	case PauseMenu::Exit:
		_gameState = Exiting;
		break;
	case PauseMenu::Continue:
		_gameState = Playing;
		break;
	case PauseMenu::TryAgain:
		_gameState = Uninitialized;
		_gameObjectManager.RemoveAll();
		Game::Start();
		break;
	}
}

void Game::ObstacleGenerator(float secondes) {
	nbrObstacles = 10 + ((int)secondes) % 30;  //toute les 30 s, on ajoute un obstacle
	if (_gameObjectManager.GetObjectCount() < nbrObstacles+2) {//+2 car il y a le sol et le joueur
		if ((rand() % 200) == 42) { //1 chance sur 200 de generer un block, et pour le 42... pourquoi pas ? :p
			if ((rand() % 2) == 0) {
				pugi::xml_document doc;
				doc.load_file("../RunFor10h01/sourceXML/ObstacleBas.xml");
				pugi::xml_node root = doc.child("VisibleGameObject");
				Obstacle* monObsBas = new Obstacle(root, myWorld);
				_gameObjectManager.Add(monObsBas); //obstacle bas
			}
			
			else {
				pugi::xml_document doc;
				doc.load_file("../RunFor10h01/sourceXML/ObstacleHaut.xml");
				pugi::xml_node root = doc.child("VisibleGameObject");
				Obstacle* monObsHaut = new Obstacle(root, myWorld);
				_gameObjectManager.Add(monObsHaut); //obstacle haut
			}
		}
	}

}


const GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
b2World* Game::myWorld =nullptr;
int Game::nbrObstacles;
sf::Clock Game::clock;