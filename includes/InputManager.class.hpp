#pragma once

#define MAX_KEY_PRESS 3

typedef enum eKey {
	KeyUp,
	KeyDown,
	KeyLeft,
	KeyRight,
	KeySpace,
	KeyExit,
	KeyNone
} Key;

class InputManager {
   public:
	InputManager();
	InputManager(const InputManager& src);
	~InputManager();

	InputManager& operator=(const InputManager& rhs);


	Key readInput();
	Key readKey();
	bool isKeyPressed(Key Key);

   private:
	Key _keyPressed[MAX_KEY_PRESS];
};
