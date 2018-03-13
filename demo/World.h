#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "BFW\Scene.h"

class World : public Scene {
public:
	World();
	virtual ~World();
	Entity * a;

};

#endif // !WORLD_H
