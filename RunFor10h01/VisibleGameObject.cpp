#include "stdafx.h"
#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject(float sizeX, float sizeY)
	: _isLoaded(false),
	size(sf::Vector2f(sizeX, sizeY))
{}



VisibleGameObject::VisibleGameObject(pugi::xml_node root):
	_isLoaded(false), 
	size(sf::Vector2f(root.attribute("width").as_float(), root.attribute("height").as_float())), 
	mainBody(NULL)
{	
}

VisibleGameObject::~VisibleGameObject()
{
	mainBody->GetWorld()->DestroyBody(mainBody);
}


void VisibleGameObject::Load(std::string filename)
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::Update()
{
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (mainBody != NULL)
		return sf::Vector2f(mainBody->GetPosition().x, mainBody->GetPosition().y);

	return sf::Vector2f(-1.f, -1.f);
}

sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

sf::Vector2f VisibleGameObject::GetSize() const{
	return size; // on 
}

b2Body* VisibleGameObject::GetMainBody() const{
	return mainBody;
}

sf::Rect<float> VisibleGameObject::GetBoundingBox() {
	return sf::Rect<float>(GetPosition(), GetSize());
}