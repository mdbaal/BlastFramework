#pragma
#ifndef WORLD_H
#define WORLD_H

#include <BFW/Scene.h>
#include "Card.h"
//#include "BFW/Button.h"

class World : public Scene {
public:
	World();
	virtual ~World();
	virtual void update(float Deltatime);

	Card* card = nullptr;
	Card* card1 = nullptr;
	
	//Button* button;

private:

};
#endif // !WORLD_H
