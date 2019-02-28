#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Camera.h"

class Scene : public Entity{
public:
	Scene();
	virtual ~Scene();
	void updateScene(float deltaTime);
	void updateEntity(Entity* entity, float deltaTime);
	bool isRunning();
	void start();
	void stop();
	Camera* getCamera();
	Camera* camera;

private:
	
	bool running;
};

#endif // !SCENE_H
