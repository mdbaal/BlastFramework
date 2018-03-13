#include "World.h"


World::World() : Scene() {
	a = new Entity();
	a->addSprite("assets/Card.tga");
	this->addChild(a);

}
World::~World() {
	this->removeChild(a);
	delete a;
}