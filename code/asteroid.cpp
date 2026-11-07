#include "asteroid.h"

Asteroid::Asteroid(int score, sf::RenderWindow* window, sf::Texture* texture)
    : Object(1, window, texture) {
  body.setPosition(sf::Vector2f(rand() % 600, -100));
  body.setRotation(sf::Angle(sf::radians(rand() % 10)));
  updateScore(score);
}

bool Asteroid::update(float delta_time) {
  body.setPosition(body.getPosition() +
                   sf::Vector2f(0, delta_time * move_speed));
  return Object::update(delta_time);
}

bool Asteroid::isTooFar() { return false; }

void Asteroid::takeDamage(int damage) { Object::takeDamage(damage); }

void Asteroid::updateScore(int new_score) {
  move_speed = 20 + new_score / 20.0;
};