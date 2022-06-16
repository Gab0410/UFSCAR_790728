#include "derivada.h"
using namespace std;

Derivada::Derivada(int inteiro, char caracter, double double1)
    : Base1(inteiro), Base2(caracter), real(double1){}
double Derivada::getReal() const{
    return real;
}

ostream &operator<<(ostream &output, const Derivada &derived){
    output<<" Inteiro: "<<derived.valor<<"\n Caracter: "
    <<derived.letra<<"\nReal: "<<derived.real;

    return output;
}
