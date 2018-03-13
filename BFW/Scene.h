#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "Camera.h"

class Scene : public Entity{
public:
	Scene();
	virtual ~Scene();
	bool isRunning();
	void start();
	void stop();
	void addCamera();
	Camera* getCamera();

private:
	Camera* camera;
	bool running;
};

#endif // !SCENE_H
