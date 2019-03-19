#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>

class Color{
public:
	Color();
	Color(int _r,int _g,int _b,int _a);
	Color(glm::vec4 color);
	
	virtual ~Color();
	
	//values
	int r = 255;
	int g = 255;
	int b = 255;
	int a = 255;
	

};

#define BLACK   glm::vec4(0,   0,   0,   255) //black
#define GRAY    glm::vec4(127, 127, 127, 255) //gray
#define RED     glm::vec4(255, 0,   0,   255) //red
#define ORANGE  glm::vec4(255, 127, 0,   255) //orange
#define YELLOW  glm::vec4(255, 255, 0,   255) //yellow
#define GREEN   glm::vec4(0,   255, 0,   255) //green
#define CYAN    glm::vec4(0,   255, 255, 255) //cyan
#define BLUE    glm::vec4(0,   0,   255, 255) //blue
#define MAGENTA glm::vec4(255, 0,   255, 255) //magenta
#define PINK    glm::vec4(255, 127, 255, 255) //pink
#define WHITE   glm::vec4(255, 255, 255, 255) //white

#endif //COLOR_H