#include <unistd.h>
#include <stdlib.h>
#include "../includes/Game.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Ennemy.class.hpp"

#define NB_ENEMY 10

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
	//	Player* t = new Player(Shape(12, 3, Game::_mainWindow.getX() / 2,
	//	                             _mainWindow.getY() / 2,
	//	                             "__---^^---______________------------"));
	Player* t = new Player(Shape(2, 1, Game::_mainWindow.getX() / 2,
	                             _mainWindow.getY() / 2, "{}"));

	_gameObjectManager.add("testObject", t);

	_state = PLAYING;
	gameLoop();
	_state = EXITING;
}

void Game::gameLoop() {
	while (_state == PLAYING) {
		_inputManager.readInput();
		clear();
		GameObjectgenerator();
		_gameObjectManager.updateAll(_mainWindow);
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
	int rdmX = rand() % _mainWindow.getX();  // random position (0 to COLS)
	int rdmN = rand() % NB_ENEMY;            // random number (0 to ...)

	rdmN = 1;
	if (tick % 10 == 0) {
		while (rdmN--) {
			Ennemy* t = new Ennemy(Shape(1, 1, rdmX, 0, "V"));
			_gameObjectManager.add("BasicEnemy", t);
		}
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
int Game::tick = 0;

