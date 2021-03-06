#include "Core.h"

Core::Core() {
	Debug::message("[Core init]");
	renderer = Renderer(1024, 768, "demo");

}

Core::~Core() {
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

void Core::run(Scene* s) {
	while (s->isRunning() && SceneManager::getActiveScene() == s) {
		//update input
		Input::getInstance()->updateInput(renderer.window());
		//update scene
		CalcDeltaTime();
		s->updateScene(_deltaTime);
		//render the scene
		renderer.renderScene(s);
		//if the window is closed or the escape key is pressed exit the program
		if (glfwWindowShouldClose(renderer.window()) == 1 || Input::getInstance()->getKey(Esc)) { s->stop(); }

		//temp switch functions
		if (Input::getInstance()->getKeyDown(LeftBracket)) {
			SceneManager::toNext();
		}
		if(Input::getInstance()->getKeyDown(RightBracket)){
			SceneManager::toPrevious();
		}
		//
	}
	if (s->isRunning()) this->run(SceneManager::getActiveScene());
}
float Core::CalcDeltaTime() {
	static float lastTime = glfwGetTime();
	float startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}