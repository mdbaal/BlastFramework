#pragma once
#ifndef CORE_H
#define CORE_H

#include "Renderer.h"
#include "Input.h"
#include "Scene.h"
#include "Debug.h"

class Core {
public:
	Core();
	virtual ~Core();
	void run(Scene* s);

	float CalcDeltaTime();

private:
	Renderer renderer;
	float deltaTime = 0;

};


#endif // !CORE_H
