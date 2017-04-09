#include "../includes/GameObjectManager.class.hpp"
#include "../includes/GameObjectManager.class.hpp"

GameObjectManager::GameObjectManager(void) {}

GameObjectManager::GameObjectManager(const GameObjectManager& src) {
	*this = src;
}

GameObjectManager::~GameObjectManager(void) {}

GameObjectManager& GameObjectManager::operator=(const GameObjectManager& rhs) {
	(void)rhs;
	return *this;
}

void GameObjectManager::add(std::string name, GameObject* go) {
	Node* n = new Node();

	n->name = name;
	n->go = go;
	n->next = NULL;

	_gameObjectList.push(n);
}

void GameObjectManager::remove(Node* object) {
	Node* prev;
	Node* itr = _gameObjectList.begin();

	if (itr == object) {
		_gameObjectList.head = itr->next;
		delete itr;
		return;
	}

	while (itr) {
		if (itr == object) {
			prev->next = itr->next;
			delete itr->go;
			delete itr;
			return;
		}
		prev = itr;
		itr = itr->next;
	}
}

void GameObjectManager::updateAll(NDisplay& window) {
	for (Node* itr = _gameObjectList.begin(); itr; itr = itr->next) {
		itr->go->update();
		
		if (itr->go->getPosition().y > window.getY() + 1 ||
		    itr->go->getPosition().x < 0) {
			remove(itr);
		}
	}
	cleanup();
}

void GameObjectManager::drawAll(NDisplay& window) {
	for (Node* itr = _gameObjectList.begin(); itr; itr = itr->next) {
		itr->go->draw(window);
	}
}

void GameObjectManager::cleanup() {
	Node* itr = _gameObjectList.begin();
	Node* prev = NULL;

	while (itr) {
		if (!itr->go->alive) {
			if (!prev) {
				_gameObjectList.head = itr->next;
				delete itr->go;
				delete itr;
				itr = _gameObjectList.begin();
			} else {
				prev->next = itr->next;
				delete itr->go;
				delete itr;
				itr = prev->next;
			}
		} else {
			prev = itr;
			itr = itr->next;
		}
	}
}
