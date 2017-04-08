#include <stdio.h>
#include <unistd.h>

#include <input.hpp>

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
	char c = 0;

	if (read(0, &c, 1) == -1) {
		return KeyNone;
	}

	if (c == '\x1b') {  // escape sequence
		char seq[3];

		if (read(0, &seq[0], 1) != 1)
			return KeyExit;  // Escape key non followed by sequence
		if (read(0, &seq[1], 1) != 1)
			return KeyNone;

		if (seq[0] == '[') {
			switch (seq[1]) {  // Parse arrow keys
				case 'A':
					return KeyUp;
				case 'B':
					return KeyDown;
				case 'C':
					return KeyRight;
				case 'D':
					return KeyLeft;
				default:
					return KeyNone;
			}
		}
		return KeyNone;
	} else {
		return charToKey(c);
	}
}

Key InputManager::getLastInput() {
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

	return charToKey(lastInput);
}


bool InputManager::isKeyPressed(Key key) {
	for (int i = 0; i < MAX_KEY_PRESS; i++) {
		if (_keyPressed[i] == key) {
			return true;
		}
	}
	return false;
}

Key InputManager::charToKey(char c) {
	switch (c) {
		case 0x20:  // space
			return KeySpace;
		default:
			return KeyNone;
	}
}
