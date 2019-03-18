#include "input.h"
Input::Input() {
	_window = NULL;
	for (int i = 0; i < GLFW_KEY_LAST; i++) {
		keys[i] = false;
		keysUp[i] = false;
		keysDown[i] = false;
	}
	for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) {
		mouseKeys[i] = false;
		mouseKeysUp[i] = false;
		mouseKeysDown[i] = false;
	}
}

Input::~Input() {
	delete input;
}

Input* Input::input = nullptr;
Input* Input::getInstance()
{
	if (input == nullptr)
	{
		input = new Input();
	}

	return input;
}

void Input::updateInput(GLFWwindow* window) {
	if (_window == NULL)_window = window;
	glfwGetCursorPos(_window, &mouseX, &mouseY);
	
	//go through all inputs
	for (int i = 32; i<97; i++) {
		handle(i);
	}
	
	for (int i = 255; i<GLFW_KEY_LAST; i++) {
		handle(i);
	}
	for (int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		handleMouse(i);
	}
}
void Input::handle(int key) {
	//key is pressed
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
		if (keys[key] == false) {
			keys[key] = true;
			keysDown[key] = true;
		}
		else {
			keysDown[key] = false;
		}
	}
	//key is released
	if (glfwGetKey(_window, key) == GLFW_RELEASE) {
		if (keys[key] == true) {
			keys[key] = false;
			keysUp[key] = true;
		}
		else {
			keysUp[key] = false;
		}
	}
}
void Input::handleMouse(int button) {
	//mouseKey down
	if (glfwGetMouseButton(_window, button) == GLFW_PRESS) {
		if (mouseKeys[button] == false) {
			mouseKeys[button] = true;
			mouseKeysDown[button] = true;
			mouseKeysUp[button] = false;
		}
		else {
			mouseKeysDown[button] = false;
		}
	}
	//mouseKey up
	if (glfwGetMouseButton(_window, button) == GLFW_RELEASE) {
		if (mouseKeys[button] == true) {
			mouseKeys[button] = false;
			mouseKeysDown[button] = false;
			mouseKeysUp[button] = true;
		}
		else {
			mouseKeysUp[button] = false;
		}
	}
}

bool Input::getKey(KeyCode key) {
	return keys[key];
}
bool Input::getKeyDown(KeyCode key) {
	
	return keysDown[key];
}
bool Input::getKeyUp(KeyCode key) {
	
	return keysUp[key];
}
bool Input::getMouseDown(int mouseButton) {
	
	return mouseKeys[mouseButton];
}
bool Input::getMouseUp(int mouseButton) {
	
	return mouseKeysUp[mouseButton];
}
glm::vec2 Input::getMousePos() {
	return glm::vec2(mouseX, mouseY);
}