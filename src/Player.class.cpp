#include <Player.class.hpp>
#include <Game.class.hpp>
#include <debug.hpp>

Player::Player(void) {}

Player::Player(Shape s) : GameObject(s) {}

Player::Player(const Player& src) {
	*this = src;
}

Player::~Player(void) {}

Player& Player::operator=(const Player& rhs) {
	(void)rhs;
	return *this;
}

void Player::update() {
	Vector2 pos = _shape.getPosition();

	if (Game::getInputManager().isKeyPressed(KeyLeft)) {
		if (pos.x > 1) {
			pos.x--;
		}
	} else if (Game::getInputManager().isKeyPressed(KeyRight)) {
		pos.x++;
	}

	if (Game::getInputManager().isKeyPressed(KeyUp)) {
		if (pos.y > 1) {
			pos.y--;
		}
	} else if (Game::getInputManager().isKeyPressed(KeyDown)) {
		pos.y++;
	}

	_shape.setPosition(pos);
}
