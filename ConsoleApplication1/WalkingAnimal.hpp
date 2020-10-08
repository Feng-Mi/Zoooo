#pragma once
#include "Animal.hpp"

class WalkingAnimal : public Animal {
public:

	WalkingAnimal(string name, bool cleanness, bool hunger) : Animal(name, cleanness, hunger)
	{}

	//TODO: Deny moving on y (Up and Down)
	void Move(const MovingDirection& direction) override {

		//Set step as 1 (own logic may be 2, 15 e.t.c)
		Animal::MakeMove(direction, 1);
	}
};