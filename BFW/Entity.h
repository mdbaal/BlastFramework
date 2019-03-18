#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"
#include "glm/glm.hpp"
#include <vector>
#include "Input.h"
#include "debug.h"

class Entity{
public:
	Entity(std::string sprite,float x,float y,float r);
	Entity();
	virtual ~Entity();
	virtual void update(float deltaTime) = 0;

  //setters and adders
  void setSprite(std::string file);
  void addToSpriteSet(std::string file);
  void addChild(Entity* e);
  void setPosition(float x,float y,float z);
  void move(float x, float y);
  void rotate(float r);
  void setRotation(float r);
  void setScale(float x, float y, float z);
  //getters
  std::vector<Entity*> getChildren();
  glm::vec3 getPosition();
  float getRotation();
  glm::vec3 getScale();
  Sprite* getSprite();
  std::vector<Sprite*> getSpriteSet();

  Input* input() {
	  return Input::getInstance();
  }

  
  //removers and deleters
  void removeChild(Entity* e);
  void deleteSprite();

private:
  Entity * parent = NULL;
  Sprite* sprite = NULL;
  std::vector<Sprite*> spriteSet = std::vector<Sprite*>();
  glm::vec3 position = glm::vec3(0,0,0);
  glm::vec3 scale = glm::vec3(1,1,1);
  float rotation = 0;
  std::vector<Entity*> children;

};

#endif //!ENTITY_H
