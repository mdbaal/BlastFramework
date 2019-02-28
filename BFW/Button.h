#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"

class Button : public Entity{
public:
	Button(std::string sprite, float x, float y, float r);
	virtual ~Button();

private:
	
	
};

#endif // !BUTTON_H
