#include "object.h"

Object::Object(int health) : health(health), alive(true) {}

bool Object::isAlive() { return alive; }

bool Object::update(float delta_time) {
  if (!alive) {
    return true;
  }
  return false;
};

void Object::takeDamage(int damage) {
  health -= damage;
  if (health <= 0) {
    alive = false;
  }
};