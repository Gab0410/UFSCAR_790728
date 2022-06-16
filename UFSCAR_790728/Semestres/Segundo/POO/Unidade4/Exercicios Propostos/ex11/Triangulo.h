#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <cmath>
#include <iostream>
using namespace std;
class Triangulo {
    public:
        Triangulo(double,double,double);
        Triangulo(double);
        virtual ~Triangulo();

        double getPerimetro() const;
        virtual double getArea() const;

        void imprime() const;
        int compare(const Triangulo& t) const;
    protected:
        double lados[3];
};
#endif /* TRIANGULO_H */