#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "pugixml.hpp"

/** classe abstraite mere de tous les elements visibles du jeu; contient un constructeur general, ainsi que des methodes update et draw a overrider
elle contient donc a la fois un corps de box2d et un sprite de sfml*/
class VisibleGameObject
{
public:
	VisibleGameObject(float sizeX, float sizeY);
	VisibleGameObject(pugi::xml_node root);
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);

	virtual sf::Vector2f GetPosition() const;
	virtual sf::Vector2f GetSize() const;
	virtual b2Body *GetMainBody() const;
	virtual bool IsLoaded() const;
	virtual void Update();
	// std::string GetObjectType() const;

	sf::Rect<float> GetBoundingBox();
	
	const static int SCREEN_WIDTH = 1920;
	const static int SCREEN_HEIGHT = 1080;

protected:
	sf::Sprite& GetSprite();
	sf::Sprite  _sprite;

	b2Body* mainBody;

	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;

private:
	static const int SCALE = 30;
	const sf::Vector2f size ;
	
};
