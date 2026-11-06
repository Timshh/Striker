#include "asteroid.h"

Asteroid::Asteroid(int score) : Object(3) {
  updateScore(score); }

bool Asteroid::update(float delta_time) { return false; }

void Asteroid::takeDamage(int damage) {
  Object::takeDamage(damage);
}

void Asteroid::updateScore(int new_score) { move_speed = 1 + new_score / 100.0; };