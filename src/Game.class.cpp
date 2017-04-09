#include <unistd.h>
#include <stdlib.h>
#include "../includes/Game.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Ennemy.class.hpp"

Game::Game(void) {}

Game::Game(const Game& src) {
	*this = src;
}

Game::~Game(void) {}

Game& Game::operator=(const Game& rhs) {
	(void)rhs;
	return *this;
}

void Game::start() {
	Player* t = new Player(Shape(12, 3, Game::_mainWindow.getX() / 2,
	                             _mainWindow.getY() / 2,
	                             "__---^^---______________------------"));

	_gameObjectManager.add("testObject", t);

	for (int j = 4; j < 8; j++) {
		for (int i = 0; i < Game::_mainWindow.getX(); i++) {
			Ennemy* e = new Ennemy(Shape(1, 1, i, j, "%"));
			_gameObjectManager.add("testEnnemy", e);
		}
	}

	_state = PLAYING;
	gameLoop();
	_state = EXITING;
}

void Game::gameLoop() {
	while (_state == PLAYING) {
		_inputManager.readInput();
		clear();

		_gameObjectManager.updateAll();
		_gameObjectManager.drawAll(_mainWindow);

		refresh();
		usleep(13000);

		if (_inputManager.isKeyPressed(KeyExit)) {
			_state = EXITING;
		}
	}
}

InputManager& Game::getInputManager() {
	return _inputManager;
}

void Game::GameObjectgenerator() {
	int rdmX = rand() % 25;  // random position (0 to COLS)
	int rdmN = rand() % 20;  // random number (0 to ...)


	while (rdmN--) {
		GameObject* t = new GameObject(
		    Shape(1, 1, rdmX, Game::_mainWindow.getY() - 1, "V"));
		_gameObjectManager.add("BasicEnemy", t);
	}
}

NDisplay& Game::getWindow() {
	return _mainWindow;
}

GameObjectManager& Game::getGameObjectManager() {
	return _gameObjectManager;
}

void Game::triggerLose() {
	_state = LOST;
}

InputManager Game::_inputManager;
NDisplay Game::_mainWindow;
Game::eGameState Game::_state = UNINITIALIZED;
GameObjectManager Game::_gameObjectManager;
