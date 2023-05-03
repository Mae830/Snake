#include "Snake.h"
#include <iostream>


sf::Shape* Snake::Head() {
	sf::RectangleShape* rec = new sf::RectangleShape();
	rec->setSize(sf::Vector2f(50, 50));
	rec->setFillColor(sf::Color(0, 0, 255, 250));
	rec->setPosition(150, 200);
	rec->setPosition(150, 200);
	return rec;
}

sf::Shape* Snake::Mid(){
	sf::RectangleShape* rec = new sf::RectangleShape();
	rec->setSize(sf::Vector2f(50, 50));
	rec->setFillColor(sf::Color(255, 255, 0, 250));
	rec->setPosition(100, 200);
	return rec;
}



sf::Shape* Snake::Tail() {
	sf::RectangleShape* rec = new sf::RectangleShape();
	rec->setSize(sf::Vector2f(50, 50));
	rec->setFillColor(sf::Color(255, 0, 0, 250));
	rec->setPosition(50, 200);
	return rec;
}


Snake::Snake() {
	
	BodyPart* h = new BodyPart(Head());
	BodyPart* m = new BodyPart(Mid());
	BodyPart* t = new BodyPart(Tail());

	//Declare the top level pointers
	head = h;
	curr = m;
	tail = t;

	//Connect all the parts via pointers
	h->next = m;
	m->next = t;

	t->previous = m;
	m->previous = h;
}


Snake::BodyPart* Snake::GetNextPart(BodyPart* part) {
	return part->next;
}

sf::Shape* Snake::GetShape() {
	BodyPart* temp = curr;
	if (curr->next != nullptr) {
		curr = curr->next;
	}
	return temp->shape;
}

bool Snake::AtEnd() {
	if (curr->next == nullptr) {
		return true;
	}
	return false;
}

void Snake::SetToHead() {
	curr = head;
}

void Snake::moveBlock(Snake::BodyPart* block) {
	sf::Vector2f move;
	switch (block->dir) {
	case 0:
		move = { 0, 0 };
		break;
	case 1:
		move = { -50, 0 };
		break;
	case 2:
		move = { 50, 0 };
		break;
	case 3:
		move = { 0, -50 };
		break;
	case 4:
		move = { 0, 50 };
		break;
	}
	curr->shape->move(move);
	std::cout << block->dir;
}

void Snake::SetNextMovement(int val) {
	nextMove = val;
}

sf::Shape* Snake::GetHead() {
	return head->shape;
}

bool Snake::MoveHead() {
	
	curr = head;
	sf::Vector2f currPos = curr->shape->getPosition();
	sf::Vector2f newPos = curr->shape->getPosition();

	curr->dir = nextMove;
	

	if (newPos.x <= 0 && head->dir == 1) {
		return false;
	}else if (newPos.x >= 450 && head->dir == 2) {
		return false;
	}
	else if (newPos.y <= 0 && head->dir == 3) {
		return false;
	}
	else if (newPos.y >= 450 && head->dir == 4) {
		return false;
	}

	
	
	moveBlock(curr);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		curr->dir = 0;
	}

	return true;

}

bool Snake::MoveSnake(bool& crash) {
	sf::Vector2f move;
	bool moved = MoveHead();
	if (!moved) {
		return moved;
	}
	curr = curr->next;
	
	if (curr != nullptr) {
		while (curr->next != nullptr) {
			if (curr->shape->getPosition() == head->shape->getPosition()) {
				crash = true;
			}
			moveBlock(curr);
			curr = curr->next;
		}
		if (curr != nullptr) {
			if (curr->shape->getPosition() == head->shape->getPosition()) {
				crash = true;
			}
			moveBlock(curr);
		}
		while (curr->previous != nullptr) {
			curr->dir = curr->previous->dir;
			curr = curr->previous;
		}
		if (curr->previous != nullptr) {
			curr->dir = curr->previous->dir;
		}
	}
	
	std::cout << "\n";
	curr = head;
	return moved;
}

void Snake::Grow() {
	nTail = new BodyPart(Mid());
	nTail->shape->setPosition(tail->shape->getPosition().x, tail->shape->getPosition().y);
	nTail->dir = tail->dir;
}

void Snake::Attach() {
	tail->next = nTail;
	nTail->previous = tail;
	tail = nTail;
}

void Snake::Stop() {
	curr = head;
	while (curr->next != nullptr) {
		curr->dir = 0;
		curr = curr->next;
	}
	curr->dir = 0;
}

void Snake::DeleteSnake() {
	BodyPart* temp = head;
	if (temp != nullptr) {
		while (temp->next != nullptr) {
			temp = temp->next;
			delete temp;
		}
	}

	if (temp != nullptr) {
		delete temp;
	}
}

 Snake::~Snake() {
	DeleteSnake();
}




	
