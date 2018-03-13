#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Clickable.h"
class Button : public Clickable {
public:
	Button(std::string image,int x, int y,float scale);
	
	virtual ~Button();
	virtual void update(float deltatime);

private:
			
};

#endif // !BUTTON_H
