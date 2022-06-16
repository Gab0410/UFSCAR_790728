#include "Poligonos.h"

ostream& operator<<(ostream &out, const Poligonos &obj){
    out<<"Nro Lado: "<<obj.getNroLado();
    out<<"\nPerimetro: "<<obj.getPerimetro();
    out<<"\nArea: "<<obj.getArea()<<"\n";
    return out;
}

Poligonos::Poligonos(vector<double>&l)
    :lados(l){}

Poligonos::~Poligonos(){}

double Poligonos::getLado(int i) const{
    return lados[i-1];
}
double Poligonos::getPerimetro() const{
    double soma =0;
    for(int i=0;i<lados.size();i++)
         soma += lados[i];
    return soma;
}
int Poligonos::getNroLado( ) const{
    return lados.size();
}
void Poligonos::imprime() const{
    cout<<(*this);
}
bool Poligonos::comparaArea(const Poligonos* p1, const Poligonos* p2){
    if(p1->getArea() != p2->getArea())
        return (p1->getArea() < p2->getArea());
    return (p1->getPerimetro() < p2->getPerimetro());

}
bool Poligonos::comparaNroLados(const Poligonos* p1, const Poligonos* p2){
    if(p1->getNroLado() != p2->getNroLado())
        return (p1->getNroLado() < p2->getNroLado());
    return (p1->getPerimetro() < p2->getPerimetro());
}


