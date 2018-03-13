#pragma once
#ifndef ENTITY_H
#define ENTITY_H



#include "Sprite.h"
#include "glm\glm.hpp"
#include <vector>

class Entity{
public:
	Entity();
	virtual ~Entity();

  //setters and adders
  void addSprite(Sprite* s);
  void addSprite(std::string file);
  void addChild(Entity* e);
  void setPosition(float x,float y,float z);
  void setRotation(float r);
  void setScale(float x, float y, float z);
  //getters
  std::vector<Entity*> getChildren();
  glm::vec3 getPosition();
  float getRotation();
  glm::vec3 getScale();
  Sprite* getSprite();
  //removers and deleters
  void removeChild(Entity* e);
  void deleteSprite();

private:
  Entity * parent;
  Sprite* sprite;
  glm::vec3 position = glm::vec3(0,0,0);
  glm::vec3 scale = glm::vec3(1,1,1);
  float rotation = 0;
  std::vector<Entity*> children;
};

#endif //!ENTITY_H
