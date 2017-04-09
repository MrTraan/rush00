#include <unistd.h>
#include <stdlib.h>
#include "../includes/Game.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Ennemy.class.hpp"
#include "../includes/Zorg.hpp"

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
	Player* t = new Player(Shape(2, 1, Game::_mainWindow.getX() / 2,
	                             _mainWindow.getY() / 2, "{}"));

	_gameObjectManager.add("testObject", t);

	_state = PLAYING;
	gameLoop();
	_state = EXITING;
}

void Game::gameLoop() {
	int diff = 0;
	while (_state == PLAYING) {
		_time = clock();
		_inputManager.readInput();
		clear();
		userInterface();
		environmentGenerator();
		ennemyGenerator();
		_gameObjectManager.updateAll(_mainWindow);
		_gameObjectManager.drawAll(_mainWindow);

		refresh();
		diff = clock() - _time;
		usleep(13000 - diff);

		if (_inputManager.isKeyPressed(KeyExit)) {
			_state = EXITING;
		}
		tick++;
		if (!tick % 1000000 == 0)
			score++;
	}
}

InputManager& Game::getInputManager() {
	return _inputManager;
}

void Game::ennemyGenerator() {
	int rdmX =
	    rand() % (_mainWindow.getX() - _mainWindow.getBoundaries().x -
	              _mainWindow.getBoundaries().y) +
	    _mainWindow.getBoundaries().x;  // random position (in boundaries)
	int rdmN = rand() % NB_ENEMY;       // random number (0 to ...)

	rdmN = 1;
	if (tick % 20 == 0) {
		while (rdmN--) {
			Ennemy* t = new Ennemy(Shape(1, 1, rdmX, 0, "V"));
			_gameObjectManager.add("BasicEnemy", t);
			Zorg* z = new Zorg(Shape(1, 1, rdmX, 0, "Z"));
			_gameObjectManager.add("ZEnemy", z);
		}
	}
}

void Game::environmentGenerator() {
	//attron(A_STANDOUT);
		int rdmX =
	    rand() % (_mainWindow.getX() - _mainWindow.getBoundaries().x -
	              _mainWindow.getBoundaries().y) +
	    _mainWindow.getBoundaries().x;  // random position (in boundaries)
	int rdmN = rand() % NB_ENEMY;       // random number (0 to ...)

	rdmN = 1;
	if (tick % 50 == 0) {
		while (rdmN--) {
			GameObject* e = new Ennemy(Shape(1, 1, rdmX, 0, "o"));
			_gameObjectManager.add("Env", e);
		}
	}

}

void Game::userInterface() {

	for (int i = 0; i < _mainWindow.getY(); i++) {
		_mainWindow.prints(
		    "**", _mainWindow.getX() - _mainWindow.getBoundaries().y / 2, i);
		_mainWindow.prints("**", _mainWindow.getX() - 2, i);
	}
	
	for (int i = _mainWindow.getX() - _mainWindow.getBoundaries().y / 2;
	     i < _mainWindow.getX(); i++) {
		_mainWindow.print('*', i, 0);
		_mainWindow.print('*', i, _mainWindow.getY() - 1);
	}
	mvprintw(5, _mainWindow.getX() - _mainWindow.getBoundaries().y / 3,
	         "Score : %d", score);
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
NDisplay Game::_mainWindow(30, 120);
Game::eGameState Game::_state = UNINITIALIZED;
GameObjectManager Game::_gameObjectManager;
int Game::tick = 0;
int Game::score = 0;
int Game::life = 0;
clock_t Game::_time = 0;