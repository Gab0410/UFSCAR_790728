#include "Equilatero.h"

Equilatero::Equilatero(double l)
    :Triangulo(l)
    {
        cout<<"Construtor do triangulo equilatero de lado <"<<l<<">"
        <<endl;
    }
Equilatero::~Equilatero(){
        cout<<"Destrutor do triangulo equilatero de lado <"<<lados[0]
        <<">"<<endl;
}
double Equilatero::getArea() const{
    return pow(lados[0],2)*sqrt(3.0)/4;
}