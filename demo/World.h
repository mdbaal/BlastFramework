#pragma
#ifndef WORLD_H
#define WORLD_H

#include <BFW/Scene.h>
#include "BFW/Button.h"

class World : public Scene {
public:
	World();
	virtual ~World();
	virtual void update(float Deltatime);

	Entity* card;
	Button* button;

private:

};
#endif // !WORLD_H
