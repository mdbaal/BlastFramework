#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "scene.h"
#include "input.h"
#include "debug.h"
#include <map>
#include <string>

class SceneManager{
public:
	static std::map<std::string, Scene*> scenes;
	static Scene* _activeScene;

	static void addScene(std::string str, Scene* s);
	static void removeScene(std::string str);

	static void switchToScene(std::string str);
	static void toNext();
	static void toPrevious();

	static Scene* getActiveScene() { return _activeScene; };

	static void clean();
private:
	SceneManager();
	virtual ~SceneManager();
};

#endif //SCENEMANAGER_H