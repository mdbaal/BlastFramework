#include "resourceManager.h"

ResourceManager::ResourceManager(){

}

ResourceManager::~ResourceManager(){


}

std::map<std::string, Texture>    ResourceManager::_textures;
std::map<std::string, Shader>       ResourceManager::_shaders;
Shader ResourceManager::loadShader(const GLchar* vShaderFile, const GLchar* fShaderFile,std::string name) {
	Debug::message("Loading shader: " + name);
	if (!_shaders.count(name)) {
		Debug::message("New shader: " + name);
		_shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile);
	}
	_shaders[name].use();
	return _shaders[name];
}

Shader ResourceManager::getShader(std::string name) {
	return _shaders[name];
}
Texture ResourceManager::loadTexture(const GLchar* file, std::string name) {
	Debug::message("Loading texture TGA: " + name);
	if (!_textures.count(name)) {
		Debug::message("New texture: " + name);
		loadTextureFromFile(file);
	}
	return _textures[name];
}
Texture ResourceManager::getTexture(std::string name) {
	return _textures[name];
}
void ResourceManager::clear() {
	//delete all shaders	
	for (auto iter : _shaders){
		glDeleteProgram(iter.second.ID);
		}
	//delete all textures
	for (auto iter : _textures) {
		glDeleteTextures(1, &iter.second.ID);
	}
}

Shader ResourceManager::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile) {
	// Read the Vertex Shader code from the file
	std::string vertexShaderCode;
	std::string fragmentShaderCode;
	//try reading the source files 
	try {
		std::ifstream vertexShaderStream(vShaderFile, std::ios::in);
		std::ifstream fragmentShaderStream(fShaderFile, std::ios::in);

		std::string line = "";
		while (getline(vertexShaderStream, line)) {
			vertexShaderCode += "\n" + line;
		}
		vertexShaderStream.close();

		// Read the Fragment Shader code from the file
	
		line = "";
		while (getline(fragmentShaderStream, line)) {
			fragmentShaderCode += "\n" + line;
		}
		fragmentShaderStream.close();
	}
	catch (std::exception e) {
		Debug::message("ERROR::SHADER: Failed to read shader files");
	}
	//create and compile shader
	Shader shader;
	shader.compile(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
	return shader;
}
void ResourceManager::loadTextureFromFile(const GLchar* filepath) {
	FILE* file;

	unsigned char _width;
	unsigned char _height;

	unsigned char type[4];
	unsigned char info[6];

	file = fopen(filepath, "rb");

	if (!file) {
		Debug::message("error: unable to open file");
		return;
	}

	if (!fread(&type, sizeof(char), 3, file)) return;
	fseek(file, 12, SEEK_SET);
	if (!fread(&info, sizeof(char), 6, file)) return;

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		Debug::message("error: image type neither color or grayscale");
		fclose(file);
		return;
	}

	unsigned char* data;
	unsigned char bitdepth;

	_width = info[0] + info[1] * 256;
	_height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		Debug::message("bytecount not 1, 3 or 4");
		fclose(file);
		return;
	}

	// Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((_width & (_width - 1)) != 0) {
		Debug::message("warning: " + (std::string)filepath + "’s width is not a power of 2");
	}
	if ((_height & (_height - 1)) != 0) {
		Debug::message("warning: " + (std::string)filepath + "’s height is not a power of 2");
	}
	if (_width != _height) {
		Debug::message("warning: " + (std::string)filepath + " is not square");
	}

	unsigned int imagesize = _width * _height * bitdepth;

	// Create a buffer
	data = new unsigned char[imagesize];

	// Read the actual data from the file into the buffer
	if (!fread(data, 1, imagesize, file)) return;

	// Everything is in memory now, close the file
	fclose(file);

	//generate texture
	Texture texture;
	texture.generate(_width, _height, data, bitdepth);


	// OpenGL has now copied the data. Free our own version
	delete[] data;

	_textures[filepath] = texture; //assign texture
}

