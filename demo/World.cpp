#include "world.h"

World::World() {
	card = new Card("assets/card.tga",1,10,100,45);
	card1 = new Card();
	card1->setSprite("assets/card.tga", 1);
	card1->setPosition(50, 500,1);
	card1->getSprite()->setupSprite("assets/card.tga",1,.5,.5);
	this->addChild(card);
	card->addChild(card1);
	
}

World::~World() {
	delete card;
	delete card1;

	this->getChildren().clear();
}
void World::update(float deltaTime) {
	if (Input::getInstance()->getKeyDown(Z)) {
		this->removeChild(card);
	}
	
	
}