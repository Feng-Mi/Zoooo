// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Animal {       
private:           
    unsigned _id;
    string _Name;     
    bool _cleanliness;
    bool _hunger;
    

public: 
    static unsigned i;
     Animal(string Name,bool cleanliness,bool hunger) {
         i++;
         unsigned id = i;
        _id = id;
        _Name = Name;
        _cleanliness = cleanliness;
        _hunger = hunger;
    }
     void showData() {
         cout << _Name << " id:" << _id << "cleanliness:" << _cleanliness << "hunger:" << _hunger << "\n";
     }
     void Clean() {
         bool cleanliness = true;
         _cleanliness = cleanliness;
     }
     void Feed() {
         bool hunger = true;
         _hunger = hunger;
     }

};
class MovingAnimal : public Animal {
private:
    unsigned _coordinates[2]= {0,0};
public:
    void MakeStepRight(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[0] += step;
        _coordinates[0] = coordinates[0];
    }
    void MakeStepLeft(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[0] -= step;
        _coordinates[0] = coordinates[0];
    }
    void MakeStepUp(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[1] += step;
        _coordinates[1] = coordinates[1];
    }
    void MakeStepDown(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[1] -= step;
        _coordinates[1] = coordinates[1];
    }
};
class FlyingAnimal : public Animal {
private:
    unsigned _coordinates[2] = { 0,0 };
public:
    void MakeStepRight(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[0] += 2*step;
        _coordinates[0] = coordinates[0];
    }
    void MakeStepLeft(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[0] -= 2*step;
        _coordinates[0] = coordinates[0];
    }
    void MakeStepUp(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[1] += 2*step;
        _coordinates[1] = coordinates[1];
    }
    void MakeStepDown(unsigned step) {
        unsigned coordinates[2] = { 0,0 };
        coordinates[1] -= 2*step;
        _coordinates[1] = coordinates[1];
    }
};

int main() {
  
    Animal cat("first",false,false);
    Animal bird("second",false,false);

    cat.showData();
    bird.showData();

    cat.Clean();
    cat.Feed();

    bird.Clean();
    bird.Feed();

    return 0;
}

