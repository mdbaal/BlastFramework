#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <GL/glew.h>
#include <BFW/debug.h>
#include <BFW/texture.h>
#include <BFW/resourceManager.h>

class Sprite
{
	public:
		Sprite(std::string& image_path);
		virtual ~Sprite();
		//returns the texture
		Texture texture() { return _texture; };
		//returns the vertex buffer
		GLuint vertexbuffer() { return _vertexbuffer; };
		//return the uvBuffer
		GLuint uvbuffer() { return _uvbuffer; };
		//return width
		unsigned int width() { return _width; };
		//return height
		unsigned int height() { return _height; };
		//return position
		glm::vec3 getPosition() { return _position; };
		//return rotation
		float getRotation() { return _rotation; };
		//set position
		void setPosition(float x, float y) { this->_position = glm::vec3(x, y, 0); };
		//set rotation
		void setRotation(float rot) { _rotation = rot; };
	private:
		//sprites texture
		Texture _texture;
		//
		GLuint _vertexbuffer;
		//
		GLuint _uvbuffer;
		//
		unsigned int _width;
		//
		unsigned int _height;
		//
		glm::vec3 _position = glm::vec3(0, 0, 0);
		//
		float _rotation = 0;
		
};

#endif // !SPRITE_H
