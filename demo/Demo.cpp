// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <BFW/Core.h>


#include <demo/world.h>

int main( void )
{
	Core core;

	SceneManager::addScene("one",new World());
	SceneManager::addScene("two", new World());
	SceneManager::addScene("three", new World());

	core.run(SceneManager::getActiveScene());

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
