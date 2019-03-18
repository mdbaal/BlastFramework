#include "shader.h"

Shader::Shader(){

}

Shader::~Shader(){


}

Shader &Shader::use() {
	glUseProgram(this->ID);
	return *this;
}

void Shader::compile(const GLchar* vertexsource, const GLchar* fragmentSource) {
	GLuint sVertex, sFragment;

	//create vertex shader
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex,1,&vertexsource,nullptr);
	glCompileShader(sVertex);
	checkCompileErrors(sVertex,"VERTEX");

	//create fragment shader
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, nullptr);
	glCompileShader(sFragment);
	checkCompileErrors(sFragment,"FRAGMENT");

	//create shader program
	this->ID = glCreateProgram();
	glAttachShader(this->ID, sVertex);
	glAttachShader(this->ID, sFragment);
	glLinkProgram(this->ID);
	checkCompileErrors(this->ID,"PROGRAM");

	//delete shaders after linking
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);

	blendID = glGetUniformLocation(this->ID, "blendColor");
}

void Shader::checkCompileErrors(GLuint object, std::string type) {
	GLint success;
	GLchar infoLog[1024];
	//Is there an error in the compiling of the vertex or the fragment shaders
	if (type != "PROGRAM") {
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(object, 1024, nullptr, infoLog);
			Debug::message("| ERROR::SHADER: Compile-time error: Type: " + type + "\n" + "\n  -- --------------------------------------------------- -- ", Debug::red);
		}
	}
	//Is there an error in when linking the shader program
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			Debug::message("| ERROR::Shader: Link-time error: Type: " + type + "\n"
				+ infoLog + "\n -- --------------------------------------------------- -- "
				, Debug::red);
		}
	}
}