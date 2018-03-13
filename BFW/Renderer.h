#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <BFW/Sprite.h>
#include <BFW/Scene.h>

class Renderer
{
	public:
		Renderer();
		Renderer(unsigned int w, unsigned int h, char* name);
		virtual ~Renderer();

		void renderEntity(Entity* entity, glm::mat4 modelMatrix, Camera* camera);
		void renderScene(Scene* scene);
		GLFWwindow* window() { return _window; };

		unsigned int width() { return _window_width; };
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
