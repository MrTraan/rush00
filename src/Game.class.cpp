#include <Game.class.hpp>
#include <unistd.h>
#include <stdlib.h>
#include <Player.class.hpp>

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
	_state = PLAYING;
	//_mainWindow.prints("salut", _mainWindow.getX() / 2, _mainWindow.getY() /
	// 2);
	gameLoop();
	_state = EXITING;
}

void Game::gameLoop() {
	while (_state == PLAYING) {
		clear();

		_inputManager.readInput();
		_gameObjectManager.updateAll();
		_gameObjectManager.drawAll(_mainWindow);

		refresh();
		usleep(100000);

		if (_inputManager.isKeyPressed(KeyExit)) {
			_state = EXITING;
		}
	}
}

InputManager const& Game::getInputManager() {
	return _inputManager;
}

NDisplay const& Game::getWindow() {
	return _mainWindow;
}

GameObjectManager const& Game::getGameObjectManager() {
	return _gameObjectManager;
}

InputManager Game::_inputManager;
NDisplay Game::_mainWindow;
Game::eGameState Game::_state = UNINITIALIZED;
GameObjectManager Game::_gameObjectManager;
