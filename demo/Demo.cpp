// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <BFW/Core.h>

#include <demo/world.h>

int main( void )
{
	Core core;

	World* world = new World();

	core.run(world);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
