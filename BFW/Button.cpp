#include "Button.h"

Button::Button(std::string image,int x,int y,float scale) : Clickable() {
	this->position = Point(x, y);
	this->addSprite(image);
	this->scale.operator*=(scale);
}

Button::~Button() {

}
void Button::update(float deltatime) {

}
