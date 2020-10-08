#include <iostream>
#include <string>
#include <fstream>
#include "WalkingAnimal.hpp"
#include "FlyingAnimal.hpp"


using namespace std;


void ShowAnimal(const Animal& animal) {

	auto pos = animal.GetCurrentPosition();

	cout.setf(ios_base::boolalpha);

	cout << animal.GetName() << ": id: " << animal.GetId() << "; cleanliness: "
		<< animal.GetCleanliness() << "; hunger: " << animal.GetHunger()
		<< "; position: (" << pos.x << ", " << pos.y << ");" << endl;
}


//Polymorph
void ResetAnimalPosition(Animal* animal) {

	point_t pos;

	do {
		pos = animal->GetCurrentPosition();

		if (pos.x > 0)
			animal->Move(MovingDirection::Right);
		if (pos.x < 0)
			animal->Move(MovingDirection::Left);
		if (pos.y > 0)
			animal->Move(MovingDirection::Down);
		if (pos.y < 0)
			animal->Move(MovingDirection::Up);
	} while ((pos.x != 0) || (pos.y != 0));
}

int main() {

	WalkingAnimal cat("first", false, false);
	FlyingAnimal bird("second", false, false);

	ShowAnimal(cat);
	ShowAnimal(bird);

	cat.Clean();
	cat.Feed();

	bird.Clean();
	bird.Feed();

	cat.Move(MovingDirection::Left);
	bird.Move((MovingDirection)((u8_t)MovingDirection::Up | (u8_t)MovingDirection::Right));

	ShowAnimal(cat);
	ShowAnimal(bird);

	ResetAnimalPosition(&cat);
	ResetAnimalPosition(&bird);

	ShowAnimal(cat);
	ShowAnimal(bird);

	return 0;
}
