#pragma once
#include <InputManager.class.hpp>
#include "../includes/NDisplay.hpp"
#include <GameObjectManager.class.hpp>

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

   private:
	enum eGameState { PLAYING, EXITING, UNINITIALIZED };

	static void gameLoop();
	static bool isExiting();
	static eGameState _state;
	static NDisplay _mainWindow;
	static InputManager _inputManager;
	static GameObjectManager _gameObjectManager;
	static void GameObjectgenerator();
};
