#include "Retangulo.h"


Retangulo::Retangulo(vector<double>&l)
    :Poligonos(l) {}

Retangulo::~Retangulo(){}

double Retangulo::getArea() const{

    return this->getLado(1) * this->getLado(2);
}