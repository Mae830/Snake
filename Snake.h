#pragma once
#include <SFML/Graphics.hpp>

class Snake {
	struct BodyPart {
		int dir = 2;
		sf::Shape* shape = nullptr;
		BodyPart* next = nullptr;
		BodyPart* previous = nullptr;
		sf::Vector2f currMove = { 0, 0 };
		sf::Vector2f nextMove = { 0, 0 };
		BodyPart(sf::Shape* shape) {
			this->shape = shape;
		}
	};
	int nextMove = 2;
	BodyPart* head = nullptr;
	BodyPart* curr = nullptr;
	BodyPart* tail = nullptr;
	BodyPart* nTail = nullptr;
	sf::Shape* Head();
	sf::Shape* Mid();
	sf::Shape* Tail();
	//sf::Shape* TailEnd();
	BodyPart* GetNextPart(BodyPart* part);
	void moveBlock(BodyPart* part);
	
public:
	Snake();
	~Snake();
	sf::Shape* GetShape();
	bool AtEnd();
	void SetToHead();
	sf::Shape* GetHead();
	bool MoveHead();
	bool MoveSnake(bool& crash);
	void SetNextMovement(int val);
	void Grow();
	void Attach();
	void Stop();
	void DeleteSnake();

};




