#include "Scene.h"

Scene::Scene() {
	start();
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
void Scene::addCamera() {
	this->camera = new Camera();
}

Camera* Scene::getCamera() {
	return this->camera;
}

