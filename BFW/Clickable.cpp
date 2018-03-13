#include "Clickable.h"


Clickable::Clickable() {
}
Clickable::~Clickable() {


}
bool Clickable::isClickedOn() {
	if(input()->getMouseDown(0)) {
		if(input()->getMouseY() > (this->position.y - this->sprite()->size.y / 2) && input()->getMouseY() < this->position.y + this->sprite()->size.y / 2) {
		if(input()->getMouseX() > (this->position.x - this->sprite()->size.x / 2) && input()->getMouseX() < this->position.x + this->sprite()->size.x / 2) {
				return true;
			}
		}
	}
	
	return false;
}
bool Clickable::isClickedOnGame() {
	if (input()->getMouseDown(0)) {
		if (input()->getMouseY() < (this->position.y - this->sprite()->size.y / 2) || input()->getMouseY() > this->position.y + this->sprite()->size.y / 2) {
			if (input()->getMouseX() < (this->position.x - this->sprite()->size.x / 2) || input()->getMouseX() > this->position.x + this->sprite()->size.x / 2) {
				return true;
			}
		}
	}
	return false;
}
