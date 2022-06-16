#include "Liger.h"

Liger::Liger(float weight) :
Lion(weight), Tiger(weight) {
    cout<<"Construtor de Liger de peso "<<Tiger::getWeight()<<endl;
}

Liger::~Liger() {
        cout<<"Destrutor de Liger de peso "<<Tiger::getWeight()<<endl;

}

float Liger::getWeight() const {
    return Tiger::getWeight();
}
