#include "Card.h"


Card::Card(std::string sp,float x, float y, float r) : Entity(sp, x, y, r) {

}


Card::~Card() {
	
}
void Card::update(float deltatime) {
	if (Input::getInstance()->getKey(D)){
		this->move(1,0);
	}
	if (Input::getInstance()->getKey(A)) {
		this->move(-1, 0);
	}
	if (Input::getInstance()->getKey(W)) {
		this->move(0, -1);
	}
	if (Input::getInstance()->getKey(S)) {
		this->move(0, 1);
	}

}




