#include "game_control.h"

GameControl::GameControl()
    : state(GameStates::kMenu), high_score(0), manager(ResourceManager()) {
  gamemode.reset(new Gamemode());
  state = GameStates::kPlaying;
}

void GameControl::run() {
  sf::RenderWindow render_window(sf::VideoMode({1366, 768}), "Striker",
                                sf::State::Windowed);
  while (render_window.isOpen()) {
    if (auto event = render_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) render_window.close();
    }
    update();
  }
}

void GameControl::update() {
  float delta_time = time.restart().asSeconds();
  switch (state) {
    case GameStates::kMenu:
      break;
    case GameStates::kPlaying:
      gamemode->update(delta_time);
      break;
  }
};