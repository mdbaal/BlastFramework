#pragma once
#ifndef CARD_H
#define CARD_H

#include "BFW/Entity.h"
//#include "text.h"
class Card : public Entity {
public:
	Card(std::string sp,int f,float x,float y,float r);
	virtual ~Card();
	virtual void update(float deltatime);
	
private:

};

#endif // !CARD_H
