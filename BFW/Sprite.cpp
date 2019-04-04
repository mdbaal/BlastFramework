#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "sprite.h"

Sprite::Sprite() {
	_width = 0;
	_height = 0;
}

Sprite::Sprite(std::string& image_path,int filter)
{
	setupSprite(image_path, filter, 1, 1);
}



Sprite::~Sprite()
{
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_uvbuffer);
}

void Sprite::setupSprite(std::string image_path, int filter, float uvWidth, float uvHeight) {
	// these will be set correctly in loadTexture()
	_width = 0;
	_height = 0;
	_filter = filter;
	// Load image as texture via resource manager
	this->_texture = ResourceManager::loadTexture(image_path.c_str(), image_path, _filter);
	this->_width = _texture.width;
	this->_height = _texture.height;

	GLfloat g_vertex_buffer_data[18] = {
		 0.5f * _width, -0.5f * _height, 0.0f,
		-0.5f * _width, -0.5f * _height, 0.0f,
		-0.5f * _width,  0.5f * _height, 0.0f,

		-0.5f * _width,  0.5f * _height, 0.0f,
		 0.5f * _width,  0.5f * _height, 0.0f,
		 0.5f * _width, -0.5f * _height, 0.0f
	};

	// Two UV coordinates for each vertex.
	GLfloat g_uv_buffer_data[12] = {
		uvWidth, uvHeight,
		0.0f, uvHeight,
		0.0f, 0.0f,

		0.0f, 0.0f,
		uvWidth, 0.0f,
		uvWidth,uvHeight
	};

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &_uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}


