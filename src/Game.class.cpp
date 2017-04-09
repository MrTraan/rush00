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
	if (_mainWindow.getX() < 70 || _mainWindow.getY() < 70)
	{
		std::cout<<"Window too small"<<std::endl;
		exit(0);
	}

	Player* t = new Player(Shape(7, 1, Game::_mainWindow.getX() / 2,
								 _mainWindow.getY() - _mainWindow.getY() / 5, "__{!}__"));

	_gameObjectManager.add("Player", t);

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
		usleep(20000 - diff);

		if (_inputManager.isKeyPressed(KeyExit)) {
			_state = EXITING;
		}
		tick++;
		if (!tick % 100000000 == 0)
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
			Ennemy* t = new Ennemy(Shape(3, 1, rdmX - 3, 0, "vvv"));
			_gameObjectManager.add("BasicEnemy", t);
			Zorg* z = new Zorg(Shape(4, 2, rdmX - 21, 0, "zzz  zzz"));
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
		    "**", _mainWindow.getX() - _mainWindow.getBoundaries().y, i);
		_mainWindow.prints("**", _mainWindow.getX() - 2, i);
	}
	
	for (int i = _mainWindow.getX() - _mainWindow.getBoundaries().y;
	     i < _mainWindow.getX(); i++) {
		_mainWindow.print('*', i, 0);
		_mainWindow.print('*', i, _mainWindow.getY() - 1);
	}
	mvprintw(5, _mainWindow.getX() - _mainWindow.getBoundaries().y + 10,
	         "Score : %d", score);

	_mainWindow.prints("Life :", _mainWindow.getX() - _mainWindow.getBoundaries().y + 10, 8);
	attron(COLOR_PAIR(2));
	for (int i = 0; i < life / 2; i++){
		
		attron(A_REVERSE);
		_mainWindow.print(' ', i + _mainWindow.getX() - _mainWindow.getBoundaries().y + 10 , 9);
		attroff(A_REVERSE);
	}
	attroff(COLOR_PAIR(2));

	_mainWindow.prints("Press 'q' to quit the game", _mainWindow.getX() - _mainWindow.getBoundaries().y + 10, 15);

	for (int i = 88; i <90;i++)
	{
		for (int j = 0; j < _mainWindow.getY();j++)
		_mainWindow.print('*', i,j);
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
NDisplay Game::_mainWindow(100, 120);
Game::eGameState Game::_state = UNINITIALIZED;
GameObjectManager Game::_gameObjectManager;
int Game::tick = 0;
int Game::score = 0;
int Game::life = 100;
clock_t Game::_time = 0;
