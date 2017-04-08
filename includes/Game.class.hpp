#pragma once
#include <NDisplay.hpp>
#include <InputManager.class.hpp>
#include <Shape.hpp>
#include "../includes/Shape.hpp"
#include "../includes/NDisplay.hpp"

class Game {
   public:
	Game(void);
	Game(const Game& src);
	~Game(void);

	Game& operator=(const Game& rhs);

	static void start();

	static InputManager const& getInputManager();
	static NDisplay const& getWindow();
	Shape *test; 
   private:
	enum eGameState { PLAYING, EXITING, UNINITIALIZED };

	static void gameLoop();
	static bool isExiting();
	static eGameState _state;
	static NDisplay _mainWindow;
	static InputManager _inputManager;
};
