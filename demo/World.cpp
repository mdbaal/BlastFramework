#include "world.h"

World::World() {
	card = new Card("assets/card.tga",10,100,45);
	card1 = new Card("assets/card.tga", 10, 500, 0);
	
	this->addChild(card);
	card->addChild(card1);
	
}

World::~World() {
	delete card;
	delete card1;
	

	this->getChildren().clear();
}
void World::update(float deltaTime) {
	if (Input::getInstance()->getKeyDown(Q)) {
		this->removeChild(card);
	}
	
}