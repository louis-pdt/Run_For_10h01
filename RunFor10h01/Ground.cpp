#include "stdafx.h"
#include "Ground.h"

Ground::Ground(b2World* World, float X, float Y) :
	VisibleGameObject((10240.f / 2) / 30.f, (16.f / 2) / 30.f) 
{
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(X/30.f, Y/30.f); //set the starting position
	myBodyDef.angle = 0; //set the starting angle

	mainBody = World->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(GetSize().x, GetSize().y);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 0;
	mainBody->CreateFixture(&boxFixtureDef);

	Load("../RunFor10h01/images/Wall.png");
	assert(IsLoaded());
	GetSprite().setPosition((GetPosition().x - GetSize().x) * 30.f, (GetPosition().y - GetSize().y) * 30.f);
	
}

Ground::Ground(pugi::xml_node root, b2World *World) : VisibleGameObject(root) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(root.attribute("posX").as_float(), root.attribute("posY").as_float()); //set the starting position
	myBodyDef.angle = 0; //set the starting angle

	mainBody = World->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(GetSize().x, GetSize().y);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 0;
	mainBody->CreateFixture(&boxFixtureDef);

	Load("../RunFor10h01/images/Ground.png");
	assert(IsLoaded());
	GetSprite().setPosition((GetPosition().x - GetSize().x) * 30.f, (GetPosition().y - GetSize().y) * 30.f);
}

void Ground::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}
/*
std::string GetObjectType() {
	return "static";
}*/