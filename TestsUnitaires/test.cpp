#include "pch.h"
#include "../RunFor10h01/Game.h"

TEST(Test1, TestConstructeurPlayer) {
	b2Vec2 gravity(0, -10.f);
	b2World *myWorld = new b2World(gravity);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../RunFor10h01/sourceXML/TestPugi.xml");

	pugi::xml_node root = doc.child("VisibleGameObject");

	Player *player1 = new Player(root, myWorld);

	EXPECT_FLOAT_EQ(player1->GetPosition().x, 4.f);
	EXPECT_FLOAT_EQ(player1->GetPosition().y, 5.f);

	EXPECT_FLOAT_EQ(player1->GetSize().x, 0.6f);
	EXPECT_FLOAT_EQ(player1->GetSize().y, 2.f);

	EXPECT_FLOAT_EQ(player1->GetMainBody()->GetLinearVelocity().x, 0.f);
	EXPECT_FLOAT_EQ(player1->GetMainBody()->GetLinearVelocity().y, 0.f);
}

TEST(Test2, TestConstructeurObstacle) {
	b2Vec2 gravity(0, 10.f);
	b2World *myWorld = new b2World(gravity);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("../RunFor10h01/sourceXML/TestPugi.xml");

	pugi::xml_node root = doc.child("VisibleGameObject");

	Obstacle *obstacleBas = new Obstacle(root, myWorld);

	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().x, 4.f);
	EXPECT_FLOAT_EQ(obstacleBas->GetPosition().y, 5.f);

	EXPECT_FLOAT_EQ(obstacleBas->GetSize().x, 0.6f);
	EXPECT_FLOAT_EQ(obstacleBas->GetSize().y, 2.f);
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().x, -50.f); 
	EXPECT_FLOAT_EQ(obstacleBas->GetMainBody()->GetLinearVelocity().y, 10.f);
}
