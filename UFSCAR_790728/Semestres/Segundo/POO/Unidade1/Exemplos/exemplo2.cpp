#include <stdlib.h>
#include <iostream>
#include <stdbool.h>

class horario{

    private:
        int hora;
        int minuto;
        int segundo;
    public:
        horario() {hora = 10;minuto = 5; segundo = 2;}//construtor
        horario(int,int,int); //construtor com 3 parametros
        bool acerta_hora(int);
        bool acerta_minuto(int);
        bool acerta_segundo(int);
        int get_hora();
        int get_minuto();
        int get_segundo();
        void imprime();
        ~horario(); //destruidor

};
horario::horario(int a,int b, int c){
    hora = minuto = segundo = 0;
    if(acerta_hora(a))
        hora = a;
    if(acerta_minuto(b))
        minuto = b;
    if(acerta_segundo(c))
        segundo = c;
}

horario::~horario(){ /*vazio*/}

bool horario::acerta_hora(int a){
    if(a < 24 && a>=0)
        return true;
    return false;
}
bool horario::acerta_minuto(int b){
    if(b < 60 && b >=0)
        return true;
    return false;
        
}
bool horario::acerta_segundo(int c){
    if(c<60 && c>=0)
        return true;
    return false;
}
int horario::get_hora(){
    return hora;
}
int horario::get_minuto(){
    return minuto;
}
int horario::get_segundo(){
    return segundo;
}
void horario::imprime(){
    std::cout << "Hora = " <<hora<<std::endl;
    std::cout << "Minuto = " <<minuto<<std::endl;
    std::cout<< "Segundo = "<<segundo<<std::endl;
}
int main(){
    horario acordar,almocar(12,30,0), dormir(21,30,45);

    if(almocar.acerta_hora(almocar.get_hora()) && almocar.acerta_minuto(almocar.get_minuto()) && almocar.acerta_segundo(almocar.get_segundo()))
        almocar.imprime();
    std::cout<<"\n"<<std::endl;
    if(acordar.acerta_hora(acordar.get_hora()) && acordar.acerta_minuto(acordar.get_minuto()) && acordar.acerta_segundo(acordar.get_segundo()))
        acordar.imprime();
    std::cout<<"\n"<<std::endl;
    if(dormir.acerta_hora(dormir.get_hora()) && dormir.acerta_minuto(dormir.get_minuto()) && dormir.acerta_segundo(dormir.get_segundo()))
        dormir.imprime();
    std::cout<<"\n"<<std::endl;

    return 0;
}