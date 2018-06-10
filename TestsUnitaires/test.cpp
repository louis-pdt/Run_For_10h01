#include "pch.h"
#include "../RunFor10h01/Game.h"

TEST(Test1, TestConstructeurPlayer) {
	b2Vec2 gravity(0, -10.f);
	b2World *myWorld = new b2World(gravity);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../RunFor10h01/sourceXML/Player.xml");

	pugi::xml_node root = doc.child("VisibleGameObject");

	Player *player1 = new Player(root, myWorld);

	EXPECT_FLOAT_EQ(player1->GetPosition().x, 1.f);
	EXPECT_FLOAT_EQ(player1->GetPosition().y, 1080.f / 4.f);

	EXPECT_FLOAT_EQ(player1->GetSize().x, 0.3f);
	EXPECT_FLOAT_EQ(player1->GetSize().y, 1.f);
}

TEST(Test2, TestConstructeurObstacleBas) {
	b2Vec2 gravity(0, 10.f);
	b2World *myWorld = new b2World(gravity);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../RunFor10h01/sourceXML/ObstacleBas.xml");

	pugi::xml_node root = doc.child("VisibleGameObject");

	Obstacle *obstacleBas = new Obstacle(root, myWorld);

	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().x, 1920.f/30.f);
	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().y, (1080.f-45.f) / 30.f);

	EXPECT_FLOAT_EQ(obstacleBas->GetSize().x, 1.5f);
	EXPECT_FLOAT_EQ(obstacleBas->GetSize().y, 1.5f);
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().x, -12.f); 
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().y, 0.f);
}

TEST(Test3, TestConstructeurObstacleHaut) {
	b2Vec2 gravity(0, 10.f);
	b2World *myWorld = new b2World(gravity);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../RunFor10h01/sourceXML/ObstacleHaut.xml");

	pugi::xml_node root = doc.child("VisibleGameObject");

	Obstacle *obstacleBas = new Obstacle(root, myWorld);

	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().x, 1920.f / 30.f);
	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().y, (1080.f - 120.f) / 30.f);

	EXPECT_FLOAT_EQ(obstacleBas->GetSize().x, 1.5f);
	EXPECT_FLOAT_EQ(obstacleBas->GetSize().y, 1.5f);
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().x, -12.f);
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().y, 0.f);
}