#pragma once

#define MAX_KEY_PRESS 3

class InputManager {
   public:
	InputManager();
	InputManager(const InputManager& src);
	~InputManager();

	InputManager& operator=(const InputManager& rhs);
	typedef enum eKey { Up, Down, Left, Right, Space, Exit, None } Key;


	Key getLastInput();
	bool isKeyPressed(Key Key);
	Key charToKey(char c);
	Key readKey();

   private:
	Key _keyPressed[MAX_KEY_PRESS];
};
