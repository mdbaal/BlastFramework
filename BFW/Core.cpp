
#include "Core.h"

Core::Core() {
	renderer = Renderer(1024, 768, "Demo");
}

Core::~Core() {

}

void Core::run(Scene* s) {
	//update input

	//update camera

	//update scene

	//render the scene
	renderer.renderScene(s);

	if (glfwWindowShouldClose(renderer.window()) == 1) { s->stop(); }
}
float Core::CalcDeltaTime() {
	


	return deltaTime;
}