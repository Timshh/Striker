#include "player.h"

Player::Player(sf::RenderWindow* window, sf::Texture* ship_texture,
               sf::Texture* missile_texture)
    : Object(3, window, ship_texture),
      fire_speed(1),
      fire_cd(0),
      position(0), missile_texture(missile_texture) {
}

bool Player::update(float delta_time) {
  Object::update(delta_time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    position = std::max(position - delta_time * 1.0, -1.0);
  } else {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      position = std::min(position + delta_time * 1.0, 1.0);
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && fire_cd <= 0) {
    fire_cd = 1.0 / fire_speed;
  }
  body.setPosition({300 + position * 300, 470});
  window->draw(body);
  return false;
}

void Player::takeDamage(int damage) { Object::takeDamage(damage); }

void Player::updateScore(int new_score) { fire_speed = 1 + new_score / 25; };