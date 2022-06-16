#include <iostream>
#include <math.h>
#define PI 3.1415
using namespace std;
class Ponto{
    public:
        Ponto(int=0,int=0);

        void setX(int);
        int getX();

        void setY(int);
        int getY();

        void print();

    private:
        int x,y;

};
class Circulo:public Ponto{
    public:
        Circulo(int=0,int=0,double=0.0);

        void setRaio(double);
        double getRaio();
        double getDiametro();
        double getCircunf();
        double getArea();
        void print();
    private:
        double raio;
};
Ponto::Ponto(int vx,int vy){
    x = vx;
    y = vy;
}
void Ponto::setX(int vx){
    x = vx;
}
int Ponto::getX(){
    return x;
}
void Ponto::setY(int vy){
    y = vy;
}
int Ponto::getY(){
    return y;
}

void Ponto::print(){
    cout<<"["<<x<<", "<<y<<"]"<<endl;
}

Circulo::Circulo(int vx,int vy, double r){
    setX(vx);
    setY(vy);
    setRaio(r);
}
void Circulo::setRaio(double ra){
    raio = ra;
}
double Circulo::getRaio(){
    return raio;
}
double Circulo::getDiametro(){
    return 2*raio;
}
double Circulo::getCircunf(){
    return PI*getDiametro();
}
double Circulo::getArea(){
    return PI*(pow(getRaio(),2));
}
void Circulo::print(){
    cout<<"Informaçoes sobre a circunferencia de raio = "<<raio<<", ponto x = "<<getX()<<", ponto y = "<<getY()<<endl;
    cout<<"Diametro = "<<getDiametro()<<"\nCircunferencia = "<<getCircunf()<<"\nArea = "<<getArea()<<endl;
}


int main(){
    Ponto p(72,115);
    Circulo c(p.getX(),p.getY(),4.5);

    cout<<"X = "<<p.getX()<<"\nY = "<<p.getY()<<endl;
    p.setX(10);
    p.setY(11);

    cout<<"A nova posição é: \n";
    p.print();

    c.print();
    return 0;
}