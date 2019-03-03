#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

class Debug{
public:
	Debug();
	virtual ~Debug();
	void message(std::string msg) { std::cout << std::endl << msg << std::endl; }
private:

};

#endif //DEBUG_H