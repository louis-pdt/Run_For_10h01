#include "stdafx.h"
#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(b2World* World, float X, float Y) :
	VisibleGameObject(1.5f, 1.5f) {
		b2BodyDef myBodyDef;
		myBodyDef.type = b2_kinematicBody; 
		myBodyDef.position.Set(X / 30.f, Y / 30.f); //set the starting position
		myBodyDef.fixedRotation = true; //le player ne tourne pas

		mainBody = World->CreateBody(&myBodyDef);

		b2PolygonShape boxShape;
		boxShape.SetAsBox(GetSize().x, GetSize().y);

		b2FixtureDef boxFixtureDef;
		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = 0.05f;
		mainBody->CreateFixture(&boxFixtureDef);

		mainBody->SetLinearVelocity(b2Vec2(-12, 0));
		srand(time(NULL));
}

Obstacle::Obstacle(pugi::xml_node root, b2World* World) : VisibleGameObject(root) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_kinematicBody;
	myBodyDef.position.Set(root.attribute("posX").as_float(), root.attribute("posY").as_float()); //set the starting position
	myBodyDef.fixedRotation = true; //le player ne tourne pas

	mainBody = World->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(GetSize().x, GetSize().y);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = root.attribute("density").as_float();
	mainBody->CreateFixture(&boxFixtureDef);

	mainBody->SetLinearVelocity(b2Vec2(root.attribute("linVelX").as_float(), root.attribute("linVelY").as_float()));
	srand(time(NULL));

	if (GetSize().x > GetSize().y)
		Load("../RunFor10h01/images/ObstacleBas2.png");
	else 
		Load("../RunFor10h01/images/ObstacleHaut2.png");

	assert(IsLoaded());
	GetSprite().setPosition((GetPosition().x - GetSize().x) * 30.f, (GetPosition().y - GetSize().y) * 30.f);


}

Obstacle::~Obstacle() {
}

void Obstacle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

void Obstacle::Update() {
	if (mainBody->GetPosition().x <= 0 && (rand()%200) ==42) {
		mainBody->SetTransform(b2Vec2(1920.f/30, mainBody->GetPosition().y), 0);//on deplace le bloc sorti tout a gauche a droite de l ecran
	}
	
	GetSprite().setPosition((GetPosition().x - GetSize().x) * 30.f, (GetPosition().y - GetSize().y) * 30.f);
}
