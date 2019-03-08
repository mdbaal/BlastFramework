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
		
};

#endif // !SPRITE_H
