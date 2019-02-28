#include "world.h"
#include "Card.h"
#include "BFW/Core.h"

World::World() {
	card = new Card("assets/card.tga",10,100,0);
	this->addChild(card);
}

World::~World() {
	this->removeChild(card);
	delete card;
	

	this->getChildren().clear();
}
void World::update(float deltaTime) {
	
}