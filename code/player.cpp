#include "player.h"

Player::Player(sf::RenderWindow* window, sf::Texture* ship_texture,
               sf::Texture* missile_texture)
    : Object(3, window, ship_texture),
      fire_speed(1),
      fire_cd(0),
      position(0),
      missile_texture(missile_texture) {}

bool Player::update(float delta_time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    position = std::max(position - delta_time * 1.0, -1.0);
  } else {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      position = std::min(position + delta_time * 1.0, 1.0);
    }
  }

  fire_cd -= delta_time;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && fire_cd <= 0) {
    fire_cd = 1.0 / fire_speed;
    missiles.push_back(Missile(window, missile_texture,
                               sf::Vector2f(300 + position * 280, 470)));
  }

  body.setPosition(sf::Vector2f(300 + position * 280, 470));
  for (Missile& target : missiles) {
    target.update(delta_time);
  }

  erase_if(missiles, [](Missile &a) { return !a.isAlive() || a.isTooFar(); });
  
  return Object::update(delta_time);
}

int Player::getHP() { return health; }

void Player::takeDamage(int damage) { Object::takeDamage(damage); }

void Player::updateScore(int new_score) { fire_speed = 1 + new_score / 25; }

std::vector<Missile>* Player::getMissiles() { return &missiles; };