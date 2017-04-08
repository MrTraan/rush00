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


	Key getLastInput();
	Key charToKey(char c);
	Key readKey();
	static bool isKeyPressed(Key Key);

   private:
	static Key _keyPressed[MAX_KEY_PRESS];
};
