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

InputManager::Key InputManager::readKey() {
	char c = 0;

	if (read(0, &c, 1) == -1) {
		return None;
	}

	if (c == '\x1b') {  // escape sequence
		char seq[3];

		if (read(0, &seq[0], 1) != 1)
			return Exit;  // Escape key non followed by sequence
		if (read(0, &seq[1], 1) != 1)
			return None;

		if (seq[0] == '[') {
			switch (seq[1]) {  // Parse arrow keys
				case 'A':
					return Up;
				case 'B':
					return Down;
				case 'C':
					return Right;
				case 'D':
					return Left;
				default:
					return None;
			}
		}
		return None;
	} else {
		return charToKey(c);
	}
}

InputManager::Key InputManager::getLastInput() {
	Key k = None;
	Key lastInput = None;
	int i = 0;

	while ((k = readKey()) != None) {
		if (i < MAX_KEY_PRESS) {
			_keyPressed[i] = k;
			i++;
		}
	}

	while (i < MAX_KEY_PRESS) {
		// Fill keyPressed with key None
		_keyPressed[i] = None;
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

InputManager::Key InputManager::charToKey(char c) {
	switch (c) {
		case 0x20:  // space
			return Space;
		default:
			return None;
	}
}
