#pragma once
#include <InputManager.class.hpp>
#include "NDisplay.hpp"
#include <GameObjectManager.class.hpp>
#include <ctime>


class Game {
   public:
	Game(void);
	Game(const Game& src);
	~Game(void);

	Game& operator=(const Game& rhs);

	static void start();

	static InputManager& getInputManager();
	static NDisplay& getWindow();
	static GameObjectManager& getGameObjectManager();

	static void triggerLose();

	static int tick;
	static int score;
	static int nbShot;
	static int life;

   private:
	enum eGameState { PLAYING, EXITING, UNINITIALIZED, LOST };

	static void gameLoop();
	static bool isExiting();
	static eGameState _state;
	static NDisplay _mainWindow;
	static InputManager _inputManager;
	static GameObjectManager _gameObjectManager;
	static void ennemyGenerator();
	static void environmentGenerator();
	static void userInterface();
	static clock_t _time;

};
