#include "texture.h"

Texture::Texture(){
	glGenTextures(1, &this->ID);
}

Texture::~Texture(){


}
void Texture::generate(GLuint _width, GLuint _height, unsigned char* data,unsigned char bitdepth) {
	this->width = _width;
	this->height = _height;

	//create texture
	glBindTexture(GL_TEXTURE_2D, this->ID);
	// filter the Texture
	unsigned char filter = 1;
	switch (filter) {
	case 0:
		// No filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
	case 1:
		// Linear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		break;
	case 2:
		// Bilinear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		break;
	case 3:
		// Trilinear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		break;
	default:
		// No filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
	}

	// wrapping
	// GL_REPEAT, GL_MIRRORED_REPEAT or GL_CLAMP_TO_EDGE
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// handle transparency and grayscale and give the image to OpenGL
	switch (bitdepth) {
	case 4:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
		break;
	case 3:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
		break;
	case 1:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, this->width, this->height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
		break;
	default:
		Debug::message("error: bitdepth not 4, 3, or 1");
		break;
	}
	this->bind();
}

void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, this->ID);
}