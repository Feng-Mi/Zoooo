#pragma once
#include <string>
#include "MovingDirection.hpp"

using std::string;

typedef struct {
	int x;
	int y;
} point_t;


class Animal {
private:

	//It is not a public member
	static unsigned i;

	//starts with lowercase letter
	unsigned _id;
	string _name;
	bool _cleanliness;
	bool _hunger;

	//Added here cuz derived classes uses this and there is no need in writing this logic twice
	point_t _position;

protected:



	//It is impossible to create animal
	Animal(string Name, bool cleanliness, bool hunger) {

		_id = ++i;
		_name = Name;
		_cleanliness = cleanliness;
		_hunger = hunger;

		memset(&_position, 0, sizeof(point_t)); //init of position
	}


	//Added here cuz derived classes uses this and there is no need in writing this logic twice
	void MakeMove(const MovingDirection& direction, const unsigned& step) noexcept {

		if ((u8_t)direction & (u8_t)MovingDirection::Up)
			_position.y += step;

		if ((u8_t)direction & (u8_t)MovingDirection::Down)
			_position.y -= step;

		if ((u8_t)direction & (u8_t)MovingDirection::Left)
			_position.x += step;

		if ((u8_t)direction & (u8_t)MovingDirection::Right)
			_position.x -= step;
	}

public:

	unsigned GetId() const noexcept {
		return _id;
	}

	bool GetCleanliness() const noexcept {
		return _cleanliness;
	}

	bool GetHunger() const noexcept {
		return _hunger;
	}

	string GetName() const noexcept {
		return _name;
	}

	point_t GetCurrentPosition() const noexcept {
		return _position;
	}

	//Moving interface
	virtual void Move(const MovingDirection& direction) abstract;

	//This method is not a responsibility of this class it encapsulates animal logic not IO)
	/*void showData() {
		cout << _Name << " id:" << _id << "cleanliness:" << _cleanliness << "hunger:" << _hunger << "\n";
	}*/

	/*Here is no need in creating local variable "cleanliness". You are able to write value in _cleanliness field directly!*/

	void Clean() noexcept {
		_cleanliness = true;
	}

	void Feed() noexcept {
		_hunger = true;
	}
};

//init of static
unsigned Animal::i = 0;