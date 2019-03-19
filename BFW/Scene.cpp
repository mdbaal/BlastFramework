#include "Scene.h"

Scene::Scene() : Entity("",0,0,0,0) {
	this->running = true;
	this->camera = new Camera();
}
Scene::~Scene() {
	delete this->camera;
}

void Scene::start() {
	this->running = true;
}
void Scene::stop() {
	this->running = false;
}
bool Scene::isRunning() {
	return this->running;
}
void Scene::updateScene(float deltaTime) {
	updateEntity(this, deltaTime);
}
void Scene::updateEntity(Entity* entity,float deltaTime) {
	entity->update(deltaTime);

	for each (Entity* e in entity->getChildren())
	{
		updateEntity(e, deltaTime);
	}
}

Camera* Scene::getCamera() {
	return this->camera;
}

