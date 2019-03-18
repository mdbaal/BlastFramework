#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

#include "termcolor/termcolor.hpp"

class Debug{
public:
	//output a message to the console
	static void message(std::string msg) { std::cout <<  std::endl << msg << std::endl; }
private:
	Debug();
	virtual ~Debug();
};

#endif //DEBUG_H