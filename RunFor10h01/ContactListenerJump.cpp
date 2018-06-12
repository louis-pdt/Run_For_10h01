#include "stdafx.h"
#include "ContactListenerJump.h"
#include "Player.h"
#include <iostream>

int numFootContacts = 0;

void ContactListenerJump::BeginContact(b2Contact* contact) {
	//check if fixture A was the player
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Player*>(bodyUserData)->startContact();

	//check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Player*>(bodyUserData)->startContact();

}

void ContactListenerJump::EndContact(b2Contact* contact) {
	//check if fixture A was the player
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Player*>(bodyUserData)->endContact();

	//check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Player*>(bodyUserData)->endContact();
}