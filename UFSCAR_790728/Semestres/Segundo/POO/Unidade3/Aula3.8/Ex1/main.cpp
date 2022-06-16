#include <iostream>
using namespace std;

#include "increment.h"

int main(){
    Increment valor(10,5);

    cout<<"Antes do incremento "<<endl;
    valor.printI();

  /*  const Increment valor2;
    valor2.addI(); esse tipo de ação nao pode ser executada, pois valor2 é um objeto constante, e addI é um metodo que nao é constante*/

    for(int j=0;j<3;j++){
        valor.addI();
        cout<<"Pos incremento {"<<j<<"} =";
        valor.printI();
    }
    return 0;


}