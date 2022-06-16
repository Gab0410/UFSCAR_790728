#include "Triangulo.h"
#include <cmath>

Triangulo::Triangulo(vector<double> &l)
    :Poligonos(l){}

Triangulo::~Triangulo(){}

double Triangulo::getArea() const{
    double S = this->getPerimetro()/2;
    double A = S*(S-this->getLado(1))*(S-this->getLado(2))*(S-this->getLado(3));
    return sqrt(A);
}
