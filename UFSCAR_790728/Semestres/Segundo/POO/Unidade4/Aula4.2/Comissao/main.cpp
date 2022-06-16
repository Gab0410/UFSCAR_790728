#include <iostream>
#include <iomanip>

#include "Comissao.h"

using namespace std;

int main(){

    Comissao empregado("Sue","Jones","222-22-2222",10000,.06);

    cout<<fixed<<setprecision(2);

    cout<<"Empregado: "<<empregado.getFname()<<" "<<empregado.getLname()
    <<"\nSSN = "<<empregado.getSSN()
    <<"\nVenda bruta = "<<empregado.getVbruta()
    <<"\nTaxa Comissao = "<<empregado.getTaxaCom()<<endl;

    empregado.setVbruta(8000);
    empregado.setTaxaCom(.1);

    cout<<"Dados atualizados\n";

    empregado.print();

    cout<<"Lucro = "<<empregado.lucro();
}