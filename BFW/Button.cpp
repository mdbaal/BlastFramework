#include "Button.h"

Button::Button(std::string sprite,float x,float y,float r) : Entity("",0,0,0) {
	this->addSprite(sprite);
	this->setPosition(x, y,0);
	this->setRotation(r);
}
Button::~Button() {

}

