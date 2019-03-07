#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <BFW/debug.h>

#include <string>

class Shader{
public:
	Shader();
	virtual ~Shader();

	
	GLuint ID;
	// Sets the current shader as active
	Shader  &use();
	// Compiles the shader from given source code
	void compile(const GLchar *vertexSource, const GLchar *fragmentSource);
	

private:
	//check compile errors shader
	void    checkCompileErrors(GLuint object, std::string type);
	Debug debug;
};

#endif //SHADER_H