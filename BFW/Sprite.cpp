#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <BFW/sprite.h>


Sprite::Sprite(std::string& image_path)
{
	// these will be set correctly in loadTGA()
	_width = 0;
	_height = 0;

	// Load image as texture
	loadTGA(image_path.c_str());

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
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
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &_uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

Sprite::~Sprite()
{
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_uvbuffer);
	glDeleteTextures(1, &_texture.ID); // texture created in loadTGA() with glGenTextures()
}

void Sprite::loadTGA(const std::string& imagepath)
{
	debug.message("Loading TGA: " + imagepath);
	FILE *file;
	unsigned char type[4];
	unsigned char info[6];
	
	file = fopen(imagepath.c_str(), "rb");

	if (!file) {
		debug.message("error: unable to open file");
		return;
	}

	if (!fread (&type, sizeof (char), 3, file)) return;
	fseek (file, 12, SEEK_SET);
	if (!fread (&info, sizeof (char), 6, file)) return;

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		debug.message("error: image type neither color or grayscale");
		fclose(file);
		return;
	}

	unsigned char* data;
	unsigned char bitdepth;

	_width = info[0] + info[1] * 256;
	_height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		debug.message("bytecount not 1, 3 or 4");
		fclose(file);
		return;
	}

	// Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((_width & (_width - 1)) != 0) {
		debug.message("warning: " + imagepath + "’s width is not a power of 2");
	}
	if ((_height & (_height - 1)) != 0) {
		debug.message("warning: " + imagepath + "’s height is not a power of 2");
	}
	if (_width != _height) {
		debug.message("warning: " + imagepath + " is not square");
	}

	unsigned int imagesize = _width * _height * bitdepth;

	// Create a buffer
	data = new unsigned char [imagesize];

	// Read the actual data from the file into the buffer
	if (!fread(data, 1, imagesize, file)) return;

	// Everything is in memory now, close the file
	fclose(file);

	//generate texture
	this->_texture.generate(_width, _height, data, bitdepth);


	// OpenGL has now copied the data. Free our own version
	delete [] data;
}
