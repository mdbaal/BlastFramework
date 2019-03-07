#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"

#include <BFW/debug.h>

class Texture{
public:
	Texture();
	virtual ~Texture();
	// Holds the ID of the texture object, used for all texture operations to reference to this particlar texture
	GLuint ID;
	// Texture image dimensions
	GLuint width, height; // Width and height of loaded image in pixels

	// Constructor (sets default texture modes)
	// Generates texture from image data
	void generate(GLuint width, GLuint height, unsigned char* data,unsigned char bitdepth);
	// Binds the texture as the current active GL_TEXTURE_2D texture object
	void bind() const;
private:
};

#endif //TEXTURE_H