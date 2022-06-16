#include "Triangulo.h"

Triangulo::Triangulo(double l1,double l2,double l3){
 
    lados[0] = l1;
    lados[1] = l2;
    lados[2] = l3;
    cout<<"Construtor do triangulo com lados: ("<<l1<<", "<<l2<<", "
    <<l3<<")"<<endl;
}
Triangulo::Triangulo(double l){
    for(int i=0;i<3;i++)
        lados[i] = l;
    cout<<"Construtor do triangulo com lados: ("<<l<<", "<<l<<", "
    <<l<<")"<<endl;
}
Triangulo::~Triangulo(){
    cout<<"Destrutor do triangulo com lados: ("<<lados[0]<<", "
    <<lados[1]<<", "
    <<lados[2]<<")"<<endl;
}
double Triangulo::getPerimetro() const{
    double soma=0;
    for(int i=0;i<3;i++)
        soma += lados[i];

    return soma;    
}
double Triangulo::getArea() const{
    double p = this->getPerimetro()/2;
    double produto = 1;
    for(int i=0;i<3;i++)
        produto *= (p-lados[i]);
    return sqrt(produto);
}
void Triangulo::imprime() const {
    cout << "Lados: [";
    for (int i = 0; i < 3; i++) {
        cout << lados[i];
        if (i != 2) 
            cout << ",";
        
    }
    cout << "]" << endl;
    cout << "Perimetro: " << this->getPerimetro() << endl;
    cout << "Area: " << this->getArea() << endl;
}
int Triangulo::compare(const Triangulo& t) const{
    double diff = this->getArea() - t.getArea();

    return (diff<0)?-1:(diff>0)?1:0;
}
