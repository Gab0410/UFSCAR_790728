#include <iostream>
#include <iomanip>

#include "BasePlus.h"

using namespace std;

int main(){

    BasePlus empregado("Sue","Jones","222-22-2222",10000,.06, 2000);

    cout<<fixed<<setprecision(2);

    cout<<"Empregado: "<<empregado.getFname()<<" "<<empregado.getLname()
    <<"\nSSN = "<<empregado.getSSN()
    <<"\nVenda bruta = "<<empregado.getVbruta()
    <<"\nTaxa Comissao = "<<empregado.getTaxaCom()<<endl;

    empregado.setVbruta(8000);
    empregado.setTaxaCom(.1);

    BasePlus e2("Carlos","Bakery","2222222222",45,.03,10);
    
    cout<<"Dados atualizados\n";

    empregado.printd();

    cout<<"Lucro = "<<empregado.lucro();

    e2.printd();
}