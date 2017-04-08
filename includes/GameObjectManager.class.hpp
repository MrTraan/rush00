#pragma once

#include <GameObject.class.hpp>
#include <NDisplay.hpp>
#include <iostream>

struct Node {
	std::string name;
	GameObject* go;
	Node* next;
};

struct List {
	List() : head(NULL) {}
	Node* head;

	Node* begin() {
		return head;
	}

	void push(Node* n) {
		if (!head) {
			head = n;
			return;
		}

		Node* itr;
		for (itr = head; itr->next; itr = itr->next)
			;
		itr->next = n;
	}
};

class GameObjectManager {
   public:
	GameObjectManager(void);
	GameObjectManager(const GameObjectManager& src);
	~GameObjectManager(void);

	GameObjectManager& operator=(const GameObjectManager& rhs);

	void add(std::string name, GameObject* go);
	void remove(std::string name);

	void updateAll();
	void drawAll(NDisplay& window);

   private:
	List _gameObjectList;
};
