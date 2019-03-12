#ifndef TEXT_H
#define TEXT_H

#include <string>

#include <BFW/entity.h>
#include "BFW/resourceManager.h"

class Text : public Entity{
public:
	Text();
	virtual ~Text();
private:

	std::string message = "";
};

#endif //TEXT_H