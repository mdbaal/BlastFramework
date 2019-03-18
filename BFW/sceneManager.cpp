#include "sceneManager.h"

SceneManager::SceneManager(){

}

SceneManager::~SceneManager(){
	this->clean();
}

std::map<std::string, Scene*> SceneManager::scenes;
Scene* SceneManager::_activeScene;

void SceneManager::addScene(std::string str,Scene* s)
{
	scenes.insert_or_assign(str, s);
	if (scenes.size() == 1) _activeScene = s;
}

void SceneManager::removeScene(std::string str)
{
	if (scenes.at(str) == _activeScene) {
		_activeScene = scenes.end()->second;
	}
	scenes.erase(str);
	
}

void SceneManager::switchToScene(std::string str)
{
	_activeScene = scenes.at(str);
}

void SceneManager::toNext()
{
	
	for (auto it = scenes.begin(); it != scenes.end();) {
		if (it->second == _activeScene) {
			it++;
			if (it == scenes.end()) {
				_activeScene = scenes.begin()->second;
				Debug::message("to next scene: " + scenes.begin()->first, Debug::blue);
				return;
			}
			_activeScene = it->second;
			Debug::message("to next scene: " + it->first, Debug::blue);
			return;
		}
		it++;
	}
}

void SceneManager::toPrevious()
{
	for (auto it = scenes.begin(); it != scenes.end();) {
		if (it->second == _activeScene) {
			if (it == scenes.begin()) {
				it = scenes.end();
				it--;
				_activeScene = it->second;
				Debug::message("to next scene: " + it->first, Debug::blue);
				return;
			}
			it--;
			_activeScene = it->second;
			Debug::message("to next scene: " + it->first, Debug::blue);
			return;
		}
		it++;
	}
}

void SceneManager::clean()
{
	for (auto it = scenes.begin(); it != scenes.end();) {
		delete it->second;
		scenes.erase(it->first);
	}

	scenes.clear();
}
