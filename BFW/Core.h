#pragma once
#ifndef CORE_H
#define CORE_H

#include "Renderer.h"
#include "Input.h"
#include "sceneManager.h"
#include "Scene.h"
#include "debug.h"

class Core {
public:
	Core();
	virtual ~Core();
	//update the scene everyframe
	void run(Scene* s);
	//calculate the delta time
	float CalcDeltaTime();
	Renderer renderer;
private:
	float _deltaTime = 0;	
};


#endif // !CORE_H
