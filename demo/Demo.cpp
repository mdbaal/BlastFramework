
#include <GL/glew.h>

#include <glfw3.h>

#include <BFW/Core.h>
#include "World.h"

int main(void) {

	Core core;

	World* w = new World();
 
	while (w->isRunning()) {
		core.run(w);
	}


	delete w;

  return 0;
}

