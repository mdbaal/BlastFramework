#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

class Debug{
public:
	
	static void message(std::string msg) { std::cout << std::endl << msg << std::endl; }
private:
	Debug();
	virtual ~Debug();
};

#endif //DEBUG_H