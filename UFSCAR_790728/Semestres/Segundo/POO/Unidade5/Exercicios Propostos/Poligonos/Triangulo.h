#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Poligonos.h"

class Triangulo : public Poligonos {
    public:
        Triangulo(vector<double>&);
        virtual ~Triangulo();
        virtual double getArea() const;

};
#endif /* TRIANGULO_H */