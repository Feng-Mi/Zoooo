#pragma once
#include "Animal.hpp"

class FlyingAnimal : public Animal {
public:

	FlyingAnimal(string name, bool cleanness, bool hunger) : Animal(name, cleanness, hunger)
	{}

	void Move(const MovingDirection& direction) override {

		//Step is 3 cuz animal flies faster than walking
		Animal::MakeMove(direction, 3);
	}

};