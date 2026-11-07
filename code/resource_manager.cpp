#include "resource_manager.h"

ResourceManager::ResourceManager() {
  ship.loadFromFile("data/ship.png");
  missile.loadFromFile("data/missile.png");
  asteroid.loadFromFile("data/asteroid.png");
  background.loadFromFile("data/background.png");
  font.openFromFile("data/roboto.ttf");
}

sf::Font* ResourceManager::getFont() { return &font; }

sf::Texture* ResourceManager::getAsteroidTexture() { return &asteroid; }

sf::Texture* ResourceManager::getShipTexture() { return &ship; }

sf::Texture* ResourceManager::getMissileTexture() { return &missile; }

sf::Texture* ResourceManager::getBackgroundTexture() { return &background; }
