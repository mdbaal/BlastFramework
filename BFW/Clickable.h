#pragma once
#ifndef CLICKABLE_H
#define CLICKABLE_H


#include <entity.h>

class Clickable : public Entity{
public:
	 Clickable();
	 virtual ~Clickable();

	 bool isClickedOn();
	 bool isClickedOnGame();
private:

	 bool clickedOn;
};
#endif // !CLICKABLE_H
