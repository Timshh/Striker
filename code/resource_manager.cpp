#include "resource_manager.h"

ResourceManager::ResourceManager() {
  ship.loadFromFile("data/ship.png");
  missile.loadFromFile("data/ship.png");
  asteroid.loadFromFile("data/ship.png");
  background.loadFromFile("data/ship.png");
  font.openFromFile("data/roboto.ttf");
}

sf::Font* ResourceManager::getFont() { return &font; }

sf::Texture* ResourceManager::getAsteroidTexture() { return &asteroid; }

sf::Texture* ResourceManager::getShipTexture() { return &ship; }

sf::Texture* ResourceManager::getMissileTexture() { return &missile; }

sf::Texture* ResourceManager::getBackgroundTexture() { return &background; }
