#include "Tiger.h"

Tiger::Tiger(float weight) :
Animal(weight) {
   cout<<"Construtor de Tiger de peso "<<getWeight()<<endl;

}

Tiger::~Tiger() {
   cout<<"Destrutor de Tiger de peso "<<getWeight()<<endl;

}

float Tiger::getWeight() const {
   return Animal::getWeight() * 3;
}
