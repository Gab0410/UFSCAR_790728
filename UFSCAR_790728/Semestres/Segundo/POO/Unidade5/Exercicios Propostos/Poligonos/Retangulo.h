#ifndef RETANGULO_H
#define RETANGULO_H
#include "Poligonos.h"

class Retangulo :public Poligonos {
public:
Retangulo(vector<double>&);
virtual ~Retangulo();
virtual double getArea() const;
private:
};
#endif /* RETANGULO_H */