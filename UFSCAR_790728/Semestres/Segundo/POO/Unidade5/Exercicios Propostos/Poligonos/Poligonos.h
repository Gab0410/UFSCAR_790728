#ifndef POLIGONO_H
#define POLIGONO_H
#include <iostream>
#include <vector>
using namespace std;

class Poligonos{
    friend ostream& operator<<(ostream &, const Poligonos &);

    private:
        vector<double>& lados;
    public:
        Poligonos(vector<double>&);
        ~Poligonos();

        double getLado(int) const;
        double getPerimetro() const;
        int getNroLado() const;
        virtual double getArea() const = 0;

        virtual void imprime() const;
        
        static bool comparaArea(const Poligonos* p1, const Poligonos* p2);
        static bool comparaNroLados(const Poligonos* p1, const Poligonos* p2);

};

#endif