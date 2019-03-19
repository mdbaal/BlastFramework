#include "Entity.h"

Entity::Entity(std::string sprite,int filter,float x,float y,float r) {
	if(sprite != "") this->setSprite(sprite,filter);
	this->setPosition(x, y, 0);
	this->setRotation(r);
}
Entity::Entity() {

}

Entity::~Entity() {

	deleteSprite();
	
}
//adders and setters

void Entity::setSprite(std::string file,int filter) {
	deleteSprite();
	this->sprite = new Sprite(file,filter);
	this->sprite->setPosition(this->getPosition().x,this->getPosition().y);
	this->sprite->setRotation(this->getRotation());
}

void Entity::addChild(Entity* e) {
	if (e == NULL) return;
	e->parent = this;
	this->children.push_back(e);
}

void Entity::addToSpriteSet(std::string file) {
	this->spriteSet.push_back(new Sprite(file,1));
}

void Entity::setPosition(float x, float y, float z) {
	this->position = glm::vec3(x, y, z);
}
void Entity::move(float x, float y) {
	this->position.x += x;
	this->position.y += y;
}
void Entity::rotate(float r) {
	this->rotation += r;
}

void Entity::setRotation(float r) {
	this->rotation = r;
}
void Entity::setScale(float x, float y, float z) {
	this->scale = glm::vec3(x, y, z);
}
//getters
std::vector<Entity*> Entity::getChildren() {
	return this->children;
}

std::vector<Sprite*> Entity::getSpriteSet() {
	return this->spriteSet;
}

glm::vec3 Entity::getPosition() {
	return this->position;
}

float Entity::getRotation() {
	return this->rotation;
}

glm::vec3 Entity::getScale() {
	return this->scale;
}
Sprite* Entity::getSprite() {
	return this->sprite;
}
//removers and deleters
void Entity::removeChild(Entity* e) {
	if (e == nullptr) return;
	for (auto it = this->children.begin(); it != this->children.end();it++) {
		if (*it == e) {
			e->parent = nullptr;
			this->children.erase(it);
			for (int i = 0; i < e->children.size(); i++) {
				this->addChild(e->children[i]);
			}
			return;
		}
	}
}

void Entity::deleteSprite() {
	if (this->sprite != NULL) {
		delete this->sprite;
		this->sprite = NULL;
	}
}
