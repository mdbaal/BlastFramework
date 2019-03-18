#ifndef TEXT_H
#define TEXT_H

#include <string>

#include "entity.h"
#include "resourceManager.h"

class Text : public Entity{
public:
	Text();
	virtual ~Text();

	void update(float deltatime);

	void message(std::string msg);
private:

	std::string _message = "";
};

#endif //TEXT_H