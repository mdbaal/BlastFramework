#ifndef ENTITY_H
#define ENTITY_H



#include "Sprite.h"
#include "glm\glm.hpp"
#include <vector>

class Entity{
public:
  //setters and adders
  void addChild(Entity* e);
  void setPosition(float x,float y,float z);
  void setRotation(float r);
  //getters
  std::vector<Entity*> getChildren();
  glm::vec3 getPosition();
  float getRotation();


private:

  Sprite* sprite;
  glm::vec3 Position = glm::vec3(0,0,0);
  float rotation = 0;
  std::vector<Entity*> children;
};

#endif //!ENTITY_H
