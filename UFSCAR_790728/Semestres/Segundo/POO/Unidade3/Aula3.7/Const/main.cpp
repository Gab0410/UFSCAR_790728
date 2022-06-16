#include<iostream>
#include "t.h"

int main(){
    Tempo acordar(6,45,0);
    const Tempo almocar(12,0,0);

    //Testes
    acordar.setHora(18);
  //  almocar.setHora(15);nao consegue executar , pois almoçar é um objeto const, e setHora() é um metodo nao const

    almocar.printUniversal();
  //  almocar.printStandard();, nao consegue executar , pois almoçar é um objeto const, e printStandard() é um metodo nao const

    acordar.printStandard();
}