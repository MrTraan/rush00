#include <Game.class.hpp>
#include <unistd.h>
#include <stdlib.h>


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
	_state = PLAYING;
	//_mainWindow.prints("salut", _mainWindow.getX() / 2, _mainWindow.getY() / 2);
	gameLoop();
	_state = EXITING;
}

void Game::gameLoop() {
	while (_state == PLAYING) {
		_inputManager.readInput();
		_mainWindow.draw(*(new Shape(12,3, Game::_mainWindow.getX()/2, _mainWindow.getY()/2,"__---^^---______________------------")));
		// update
		// draw
		usleep(100);

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

InputManager Game::_inputManager;
NDisplay Game::_mainWindow;
Game::eGameState Game::_state = UNINITIALIZED;
