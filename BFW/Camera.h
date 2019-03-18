#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "input.h"
class Camera {
public:	 
	Camera();
	Camera(glm::vec3 position);
	//get the view matrix
	glm::mat4 getViewMatrix();
	//get the cursor
	glm::vec3 getCursor();
	//compute matrices
	void computeMatricesFromInputs(GLFWwindow* window);

	glm::mat4 _viewMatrix;

	// Initial position : on +Z
	glm::vec3 position;
	glm::vec3 cursor;

	float speed;
};
#endif // !CAMERA_H
