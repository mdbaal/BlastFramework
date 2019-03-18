#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <GL/glew.h>

#include <map>
#include <string>
#include <fstream>

#include "texture.h"
#include "shader.h"
#include "debug.h"

class ResourceManager{
public:
	//lists of shaders and textures
	static std::map < std::string, Shader> _shaders;
	static std::map < std::string, Texture> _textures;
	
	//load shader, returns a shader after completion or if it already exists
	static Shader loadShader(const GLchar* vShaderFile, const GLchar* fShaderFile,std::string name);
	//return a shader
	static Shader getShader(std::string name);
	//load texture, returns a texture after completion or if it already exists
	static Texture loadTexture(const GLchar* file,std::string name);
	//return a texture
	static Texture getTexture(std::string name);
	//clear the resource manager completely
	static void clear();
private:
	ResourceManager();
	virtual ~ResourceManager();
	//load the shader from the file
	static Shader loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile);
	//load the texture form the file
	static void loadTextureFromFile(const GLchar* file);
};

#endif //RESOURCEMANAGER_H