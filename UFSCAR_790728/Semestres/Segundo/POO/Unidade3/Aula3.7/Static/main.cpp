#include <iostream>
#include "empregado.h"

using namespace std;

int main(){

    cout<<"O numero de empregados no inicio :"<<Empregado::getContador()<<endl;

    Empregado *e1P = new Empregado("Susana", "Alves");
    Empregado *e2P = new Empregado("Roberto", "Dinamite");
    cout<<"Numero total de empregados registrados: "<<e1P->getContador()<<endl; //metodos static sao invocados por qualquer objeto da classe, ou pela propria classe

    cout<<"Empregado 1: "<<e1P->getPnome()<<" "<<e1P->getSnome()<<endl;
    cout<<"Empregado 2: "<<e2P->getPnome()<<" "<<e2P->getSnome()<<endl;

    delete  e1P;
    delete  e2P;

    e1P = 0;
    e2P = 0;

   // cout<<"O numero de empregado e: "<<e1P->getContador()<<endl;, como o objeto e1P foi deletado, não existe mais ele, logo deve-se fazer do jeito abaixo
    cout<<"O numero de empregado e: "<<Empregado::getContador()<<endl;

    return 0;



}