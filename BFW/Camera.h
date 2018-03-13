#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
class Camera {
public:	 
	glm::mat4 getViewMatrix();
	glm::vec3 getCursor();
	void computeMatricesFromInputs(GLFWwindow* window);
};
#endif // !CAMERA_H
