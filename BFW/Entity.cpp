#include "Entity.h"

void Entity::addSprite(Sprite* s) {
	this->sprite = s;
}
void Entity::addSprite(std::string file) {
	deleteSprite();
	this->sprite = new Sprite(file);
}

void Entity::addChild(Entity* e) {
	if (e == NULL) return;
	e->parent = this;
	this->children.push_back(e);
}

void Entity::setPosition(float x, float y, float z) {
	this->Position = glm::vec3(x, y, z);
}

void Entity::setRotation(float r) {
	this->rotation = r;
}

std::vector<Entity*> Entity::getChildren() {
	return this->children;
}

glm::vec3 Entity::getPosition() {
	return this->Position;
}

float Entity::getRotation() {
	return this->rotation;
}

void Entity::removeChild(Entity* e) {
	for(int i = 0;i < this->children.size();i++)
	{
		if (this->children[i] == e) {
			this->children[i]->parent = NULL;
			this->children[i] == NULL;
		}
	}
}

void Entity::deleteSprite() {
	if (this->sprite != NULL) {
		delete this->sprite;
		this->sprite = NULL;
	}
}
