#pragma once
#include <SFML/Graphics/Font.hpp>

class ResourceManager {
 public:
  ResourceManager();
  sf::Font* getFont();
  sf::Texture* getShipTexture();
  sf::Texture* getAsteroidTexture();
  sf::Texture* getMissileTexture();
  sf::Texture* getBackgroundTexture();

 private:
  sf::Font font;
  sf::Texture ship, asteroid, missile, background;
};