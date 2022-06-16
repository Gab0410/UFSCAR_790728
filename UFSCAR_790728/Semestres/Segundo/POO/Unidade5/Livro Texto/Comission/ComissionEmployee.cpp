#include <iostream>
#include <string>
#include "ComissionEmployee.h"

using namespace std;

Comissao::Comissao(const string &first, const string &last,const string &ssn, double vb,double tc)
    : fName(first),lName(last),SSN(ssn)
{
    cout<<"Construtor comissao de "<<fName<<" chamado\n";
    setVbruta(vb);
    setTaxaCom(tc);
}
Comissao::~Comissao(){
    cout<<"Destrutor comissao de "<<fName<<" chamado\n\n";

}
void Comissao::setFname(const string &first){
    fName = first;
}
string Comissao::getFname() const{

    return fName;
}
void Comissao::setLname(const string &last){
    lName = last;
}
string Comissao::getLname() const{
    return lName;
}
void Comissao::setSSN(const string &ssn){
    SSN = ssn;
}
string Comissao::getSSN() const{
    return SSN;
}
void Comissao::setVbruta(double v){
    vBruta = (v>0?v:0.0);
}
double Comissao::getVbruta() const{
    return vBruta;
}
void Comissao::setTaxaCom(double t){
    taxaCom = (t>0 && t<1.0?t:0.0);
}
double Comissao::getTaxaCom() const{
    return taxaCom;
}
double Comissao::lucro() const{
    return taxaCom*vBruta;
}
void Comissao::print() const{
    cout<<"Empregado: "<<fName<<" "<<lName
    <<"\nSSN = "<<SSN
    <<"\nVenda bruta = "<<vBruta
    <<"\nTaxa Comissao = "<<taxaCom<<endl;
}