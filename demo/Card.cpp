#include "Card.h"


Card::Card(std::string sp,float x, float y, float r) : Entity(sp, x, y, r) {

}


Card::~Card() {
	
}
void Card::update(float deltatime) {
	if (this->input()->getKey(D)){
		this->move(1,0);
	}
	if (this->input()->getKey(A)) {
		this->move(-1, 0);
	}
	
	if (input()->getKeyDown(Up)) {
		this->getSprite()->setPosition(100,0);
	}
	if (input()->getKeyDown(Down)) {
		this->getSprite()->setPosition(0,0);
	}

}




