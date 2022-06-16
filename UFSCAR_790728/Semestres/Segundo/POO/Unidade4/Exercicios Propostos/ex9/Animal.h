
#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
#include <iostream>

class Animal {
public:
    Animal(float weight);
    virtual ~Animal();
    virtual float getWeight() const;
private:
    float weight;
};

#endif /* ANIMAL_H */