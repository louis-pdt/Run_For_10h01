#include "stdafx.h"
#include "Player.h"
#include <iostream>


Player::Player(b2World* World, float X, float Y):
	VisibleGameObject(0.3f, 1.f) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	myBodyDef.position.Set(X / 30.f, Y / 30.f); //set the starting position
	myBodyDef.fixedRotation = true; //le player ne tourne pas

	mainBody = World->CreateBody(&myBodyDef);
	
	b2PolygonShape boxShape;
	boxShape.SetAsBox(GetSize().x, GetSize().y);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1.f;
	mainBody->CreateFixture(&boxFixtureDef);

	/*
	//on definie ensuite un sensor au pied du player
	boxShape.SetAsBox(0.2, 0.2, b2Vec2(0, -1), 0);
	boxFixtureDef.isSensor = true; //un sensor n engendre pas de colision 
	b2Fixture* footSensorFixture = mainBody->CreateFixture(&boxFixtureDef);*/

	stepsSinceLastJump = 0;

	Load("../RunFor10h01/images/Player1.png");
	assert(IsLoaded());
	
	GetSprite().setPosition(GetPosition().x, GetPosition().y);
}

Player::Player(pugi::xml_node root, b2World* World) : VisibleGameObject(root) {
		b2BodyDef myBodyDef;
		myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
		myBodyDef.position.Set(GetPosition().x, GetPosition().y); //set the starting position
		myBodyDef.fixedRotation = true; //le player ne tourne pas

		mainBody = World->CreateBody(&myBodyDef);

		b2PolygonShape boxShape;
		boxShape.SetAsBox(GetSize().x, GetSize().y);

		b2FixtureDef boxFixtureDef;
		boxFixtureDef.shape = &boxShape;
		boxFixtureDef.density = root.attribute("density").as_float();
		mainBody->CreateFixture(&boxFixtureDef);

		/*
		//on definie ensuite un sensor au pied du player
		boxShape.SetAsBox(0.2, 0.2, b2Vec2(0, -1), 0);
		boxFixtureDef.isSensor = true; //un sensor n engendre pas de colision
		b2Fixture* footSensorFixture = mainBody->CreateFixture(&boxFixtureDef);*/

		stepsSinceLastJump = 0;

		Load("../RunFor10h01/images/Player1.png");
		assert(IsLoaded());

		GetSprite().setPosition(GetPosition().x, GetPosition().y);
}

void Player::Jump() {
	float impulse = mainBody->GetMass() * 10;
	bool doSleep = true; /*bool autorisant ou non la methode a dormir tant qu elle n est
						 pas appelee ou utilisee*/
	mainBody->ApplyLinearImpulse(b2Vec2(0, -impulse), mainBody->GetWorldCenter(), doSleep);
	std::cout << "jump" << std::endl;
}

void Player::Update() {
	b2Vec2 vel = mainBody->GetLinearVelocity();
	float desiredVel = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		desiredVel = -maxLatVel;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		desiredVel = maxLatVel;
	}
	float velChange = desiredVel - vel.x;
	float impulse = mainBody->GetMass() * velChange; 
	mainBody->ApplyLinearImpulse(b2Vec2(impulse, 0), mainBody->GetWorldCenter(), true);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && stepsSinceLastJump > 120)
	{//pour eviter le cumul des sauts, on autorise 1 saut / 2 secondes ( on est en 120hz)
		stepsSinceLastJump = 0;
		Jump();

	}
	else stepsSinceLastJump++;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))

	GetSprite().setPosition(mainBody->GetPosition().x, mainBody->GetPosition().y);
}

void Player::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}
/*
std::string GetObjectType() {
	return "dynamic";
}*/

