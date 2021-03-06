#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

enum KeyCode
{
	Space = 32,
	Apostrophe = 39,
	Comma = 44,
	Minus = 45,
	Period = 46,
	Slash = 47,
	Alpha0 = 48,
	Alpha1 = 49,
	Alpha2 = 50,
	Alpha3 = 51,
	Alpha4 = 52,
	Alpha5 = 53,
	Alpha6 = 54,
	Alpha7 = 55,
	Alpha8 = 56,
	Alpha9 = 57,
	Semicolon = 59,
	Equal = 61,
	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,
	LeftBracket = 91,
	Backslash = 92,
	RightBracket = 93,
	GraveAccent = 96,
	Esc = 256,
	Enter = 257,
	Tab = 258,
	Backspace = 259,
	Insert = 260,
	Delete = 261,
	Right = 262,
	Left = 263,
	Down = 264,
	Up = 265,
	PageUp = 266,
	PageDown = 267,
	Home = 268,
	End = 269,
	CapsLock = 280,
	ScrollLock = 281,
	NumLock = 282,
	PrintScreen = 283,
	Pause = 284,
	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	F13 = 302,
	F14 = 303,
	F15 = 304,
	F16 = 305,
	F17 = 306,
	F18 = 307,
	F19 = 308,
	F20 = 309,
	F21 = 310,
	F22 = 311,
	F23 = 312,
	F24 = 313,
	F25 = 314,
	KeyPad0 = 320,
	KeyPad1 = 321,
	KeyPad2 = 322,
	KeyPad3 = 323,
	KeyPad4 = 324,
	KeyPad5 = 325,
	KeyPad6 = 326,
	KeyPad7 = 327,
	KeyPad8 = 328,
	KeyPad9 = 329,
	KeyPadDecimal = 330,
	KeyPadDivide = 331,
	KeyPadMultiply = 332,
	KeyPadSubtract = 333,
	KeyPadAdd = 334,
	KeyPadEnter = 335,
	KeyPadEqual = 336,
	LeftShift = 340,
	LeftControl = 341,
	LeftAlt = 342,
	LeftSuper = 343,
	RightShift = 344,
	RightControl = 345,
	RightAlt = 346,
	RightSuper = 347,
	Menu = 348
};

class Input
{
private:
	
	double mouseX;
	double mouseY;
	static Input* input;
	GLFWwindow* _window;
	//which keys are pressed/released/held down
	bool keys[GLFW_KEY_LAST];
	bool keysUp[GLFW_KEY_LAST];
	bool keysDown[GLFW_KEY_LAST];
	//which mouse buttons are pressed/released/held down
	bool mouseKeys[GLFW_MOUSE_BUTTON_LAST];
	bool mouseKeysUp[GLFW_MOUSE_BUTTON_LAST];
	bool mouseKeysDown[GLFW_MOUSE_BUTTON_LAST];
	//handle keyboard and mouse input
	void handle(int key);
	void handleMouse(int button);

	Input();
	virtual ~Input();
public:
	//return instance of input, or create one if it doesn't exist yet and return afterwards
	static Input* getInstance();
	//check the inputs for keyboard and mouse
	void updateInput(GLFWwindow* window);
	//check for a key if it is pressed 
	bool getKey(KeyCode key);
	//check if a key is held down
	bool getKeyDown(KeyCode key);
	//check if a key is released
	bool getKeyUp(KeyCode key);
	//check if a mouse button is held down
	bool getMouseDown(int mouseButton);
	//check if a mouse button is released
	bool getMouseUp(int mouseButton);
	//return the mouse position
	glm::vec2 getMousePos();
};


#endif // !INPUT_H 