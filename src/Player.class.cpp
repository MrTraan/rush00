//#include <Player.class.hpp>
#include "../includes/Player.class.hpp"
//#include <Game.class.hpp>
#include "../includes/Game.class.hpp"
//#include <debug.hpp>
#include "../includes/Laser.class.hpp"
//#include <Laser.class.hpp>

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

void Player::shoot() {
	Vector2 pos = getPosition();

	pos.y -= 1;
	pos.x = pos.x + (getWidth() / 2) - 1;
	Laser* l = new Laser(pos, Laser::defaultSpeed);

	Game::getGameObjectManager().add("laser", l);
}

void Player::update() {
	Vector2 pos = _shape.getPosition();

	if (Game::getInputManager().isKeyPressed(KeyLeft)) {
		if (pos.x > 2 + 100) {
			pos.x -= 2;
		}
	} else if (Game::getInputManager().isKeyPressed(KeyRight)) {
		if (pos.x < COLS - getWidth() - 120)
			pos.x += 2;
	}

	if (Game::getInputManager().isKeyPressed(KeyUp)) {
		if (pos.y > 1) {
			pos.y--;
		}
	} else if (Game::getInputManager().isKeyPressed(KeyDown)) {
		if (pos.y < LINES - getHeight())
			pos.y++;
	}

	if (Game::getInputManager().isKeyPressed(KeySpace)) {
		shoot();
	}
	_shape.setPosition(pos);
}

void Player::collideWithEnnemy() {
	Game::life--;
	if (Game::life == 0){
		alive = false;
		Game::triggerLose();
	}
}
