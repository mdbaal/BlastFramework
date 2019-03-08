#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <thread>

#include <BFW/camera.h>
#include <BFW/Sprite.h>
#include <BFW/Scene.h>
#include <BFW/debug.h>
#include <BFW/texture.h>
#include <BFW/shader.h>
#include <BFW/resourceManager.h>

class Renderer
{
	public:
		Renderer();
		Renderer(unsigned int w, unsigned int h, char* name);
		virtual ~Renderer();
		//render the sprite	
		void renderSprite(Sprite* sprite, glm::vec3 pos, glm::vec3 scale, float rotation, glm::mat4 viewMatrix);
		//check if the entity has a sprite and render it
		void renderEntity(Entity* entity, glm::mat4 viewMatrix, Camera* camera);
		//Go through the scene and render any entities in the scene
		void renderScene(Scene* scene);
		//get the current window
		GLFWwindow* window() { return _window; };
		//return the window width
		unsigned int width() { return _window_width; };
		//return the window height
		unsigned int height() { return _window_height; };

	private:
		int init();

		GLFWwindow* _window;
		unsigned int _window_width;
		unsigned int _window_height;
		char* _window_name;

		GLuint loadShaders(
			const char* vertex_file_path,
			const char* fragment_file_path
		);
		

		GLuint _programID;

		glm::mat4 _projectionMatrix;
};

#endif // !RENDERER_H
