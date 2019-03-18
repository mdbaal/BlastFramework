#include "camera.h"



Camera::Camera() {
	speed = 300.0f; // 300 units / second
	cursor = glm::vec3(0, 0, 0);
	position = glm::vec3(0, 0, 5);
}
Camera::Camera(glm::vec3 position) {
	speed = 300.0f; // 300 units / second
	cursor = glm::vec3(0, 0, 0);
	this->position = position;
}

 glm::mat4 Camera::getViewMatrix(){
	return _viewMatrix;
}

glm::vec3 Camera::getCursor(){
	return cursor;
}

void Camera::computeMatricesFromInputs(GLFWwindow* window)
{
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// View matrix
	_viewMatrix = glm::lookAt(
			position, // Camera is at (xpos,ypos,5), in World Space
			position + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
