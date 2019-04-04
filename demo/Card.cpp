#include "Card.h"


Card::Card(std::string sp,int f,float x, float y, float r) : Entity(sp, f,x, y, r) {

}
Card::Card(){
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

	if (input()->getKey(Q)) {
		this->rotate(-5 * deltatime);
	}
	if (input()->getKey(E)) {
		this->rotate(+5 * deltatime);
	}

	this->getSprite()->color(Color(input()->getMousePos().x - this->getPosition().x, input()->getMousePos().y - this->getPosition().y, 255, 255));

}




