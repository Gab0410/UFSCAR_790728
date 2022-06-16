#include <iostream>

#include "EmpregadoCom.h"

using namespace std;

EmpregadoCom::EmpregadoCom(const string &first,const string &last, const string &ssn,double vb,double tc)
    :Comissao(first,last,ssn)
    {
        setVbruta(vb);
        setTaxaCom(tc);
    }
void EmpregadoCom::setVbruta(double v){
    vBruta = (v>0?v:0.0);
}
double EmpregadoCom::getVbruta() const{
    return vBruta;
}
void EmpregadoCom::setTaxaCom(double t){
    taxaCom = (t>0 && t<1.0?t:0.0);
}
double EmpregadoCom::getTaxaCom() const{
    return taxaCom;
}
double EmpregadoCom::lucro() const{
    return taxaCom*vBruta;
}
void EmpregadoCom::print() const{
    Comissao::print();
    cout<<"\nVenda bruta = "<<vBruta
    <<"\nTaxa Comissao = "<<taxaCom<<endl;
}