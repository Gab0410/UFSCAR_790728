#ifndef EQUILATERO_H
#define EQUILATERO_H
#include "Triangulo.h"
class Equilatero : public Triangulo {
public:
    Equilatero(double lado);
    virtual ~Equilatero();
    double getArea() const;
    private:
};
#endif /* EQUILATERO_H */