#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

Comissao::Comissao(const string &first, const string &last,const string &ssn)
    : fName(first),lName(last),SSN(ssn)
{
    cout<<"Construtor comissao de "<<fName<<" chamado\n";
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
void Comissao::print() const{
    cout<<"Empregado: "<<fName<<" "<<lName
    <<"\nSSN = "<<SSN<<"\n";
}