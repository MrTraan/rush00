#include "Player.class.hpp"

Player::Player(void) {}

Player::Player(const Player& src) {
	*this = src;
}

Player::~Player(void) {}

Player& Player::operator=(const Player& rhs) {
	(void)rhs;
	return *this;
}

void Player::update() {}
