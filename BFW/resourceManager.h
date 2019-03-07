#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <GL/glew.h>

#include <map>
#include <string>
#include <fstream>

#include <BFW/texture.h>
#include <BFW/shader.h>
#include <BFW/debug.h>

class ResourceManager{
public:
	static std::map < std::string, Shader> _shaders;
	static std::map < std::string, Texture> _textures;
	
	static Shader loadShader(const GLchar* vShaderFile, const GLchar* fShaderFile,std::string name);

	static Shader getShader(std::string name);

	static Texture loadTexture(const GLchar* file,std::string name);

	static Texture getTexture(std::string name);

	static void clear();
private:
	ResourceManager();
	virtual ~ResourceManager();

	static Shader loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile);

	static void loadTextureFromFile(const GLchar* file);
};

#endif //RESOURCEMANAGER_H