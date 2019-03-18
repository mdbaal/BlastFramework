#include "debug.h"

Debug::Debug(){

}

Debug::~Debug(){


}

void Debug::message(std::string msg, termColor color) {
	switch (color) {
		case 0	: //grey
			std::cout << termcolor::grey << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 1: //red
			std::cout << termcolor::reset << termcolor::red << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 2: //green
			std::cout << termcolor::reset << termcolor::green << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 3: //yellow
			std::cout << termcolor::reset << termcolor::yellow<< msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 4: //blue
			std::cout << termcolor::reset << termcolor::blue << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 5: //magenta
			std::cout << termcolor::reset << termcolor::magenta << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 6: //cyan
			std::cout << termcolor::reset << termcolor::cyan << msg << std::endl;
			std::cout << termcolor::reset;
			break;
		case 7: //white
			std::cout << termcolor::reset << termcolor::white << msg << std::endl;
			std::cout << termcolor::reset;
			break;

	}

}