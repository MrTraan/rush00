#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include <InputManager.class.hpp>

InputManager::InputManager() {}

InputManager::InputManager(const InputManager& src) {
	*this = src;
}

InputManager::~InputManager() {}

InputManager& InputManager::operator=(const InputManager& rhs) {
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		_keyPressed[i] = rhs._keyPressed[i];
	}
	return *this;
}

Key InputManager::readKey() {
	int c = getch();

	switch (c) {
		case 0x20:  // space
			return KeySpace;
		case 'q':
			return KeyExit;
		case KEY_DOWN:
			return KeyDown;
		case KEY_UP:
			return KeyUp;
		case KEY_LEFT:
			return KeyLeft;
		case KEY_RIGHT:
			return KeyRight;
		default:
			return KeyNone;
	}
}

Key InputManager::readInput() {
	Key k = KeyNone;
	Key lastInput = KeyNone;
	int i = 0;

	while ((k = readKey()) != KeyNone) {
		if (i < MAX_KEY_PRESS) {
			_keyPressed[i] = k;
			i++;
		}
	}

	while (i < MAX_KEY_PRESS) {
		// Fill keyPressed with key KeyNone
		_keyPressed[i] = KeyNone;
		i++;
	}

	return lastInput;
}


bool InputManager::isKeyPressed(Key key) {
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		if (_keyPressed[i] == key)
			return true;
	}
	return false;
}
