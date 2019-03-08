#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Camera.h"

class Scene : public Entity{
public:
	Scene();
	virtual ~Scene();
	//update the scene
	void updateScene(float deltaTime);
	//update all entities in the scene
	void updateEntity(Entity* entity, float deltaTime);
	//check if the scene is still running or if the user has quit
	bool isRunning();
	//start running the scene
	void start();
	//stop running the scene
	void stop();
	//return the camera
	Camera* getCamera();
	Camera* camera; //move this to private

private:

	bool running;
};

#endif // !SCENE_H
