#include "Animal.h"

Animal::Animal(float weight) :
weight(weight) {
    cout<<"Construtor de Animal de peso "<<getWeight()<<endl;


}

Animal::~Animal() {
    cout<<"Construtor de Animal de peso "<<getWeight()<<endl;

}

float Animal::getWeight() const {
    return weight;
}



