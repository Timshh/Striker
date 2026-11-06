#pragma once

class Object {
 public:
  Object(int health);
  bool isAlive();
  virtual bool update(float delta_time);
  virtual void takeDamage(int damage);

 protected:
  bool alive;
  int health;
};