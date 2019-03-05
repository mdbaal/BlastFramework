#pragma once
#ifndef CORE_H
#define CORE_H

#include <ioStream>

#include "Renderer.h"
#include "Input.h"
#include "Scene.h"
#include "debug.h"

class Core {
public:
	Core();
	virtual ~Core();
	void run(Scene* s);
	float CalcDeltaTime();
	Renderer renderer;
private:
	float _deltaTime = 0;
	Debug debug;
	
};


#endif // !CORE_H
