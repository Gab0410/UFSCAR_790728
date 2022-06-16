#include "Lion.h"

Lion::Lion(float weight) :
Animal(weight) 
{
    cout<<"Construtor de Lion de peso "<<getWeight()<<endl;

}

Lion::~Lion() {
    cout<<"Destrutor de Lion de peso "<<getWeight()<<endl;

}

float Lion::getWeight() const {
    return Animal::getWeight();
}

