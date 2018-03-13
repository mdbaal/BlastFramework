#include "Entity.h"

Entity::Entity() {

}

Entity::~Entity() {
	//if this parent is not NULL move children to that parent and clear the list,
	//else set all parents to NULL and clear the list
	if (this->parent != NULL) {
		for (int i = this->children.size()-1;i > 0;i--)
		{
			Entity* e = this->children[i];
			this->parent->addChild(e);
			this->children[i] = NULL;
		}

		this->children.clear();
	}
	else {
		for (int i = this->children.size() - 1; i > 0; i--)
		{
			Entity* e = this->children[i];
			this->children[i] = NULL;
		}

		this->children.clear();
	}
	
}
//adders and setters
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
	this->position = glm::vec3(x, y, z);
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
	for(int i = 0;i < this->children.size();i++)
	{
		if (this->children[i] == e) {
			this->children[i]->parent = NULL;
			this->children[i] = NULL;
		}
	}
}

void Entity::deleteSprite() {
	if (this->sprite != NULL) {
		delete this->sprite;
		this->sprite = NULL;
	}
}
