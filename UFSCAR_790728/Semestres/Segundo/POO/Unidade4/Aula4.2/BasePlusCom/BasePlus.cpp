#include <iostream>

using namespace std;

#include "BasePlus.h"

BasePlus::BasePlus(const string &first, const string &last, const string &ssn, double sales, double rate, double salary)
    : Comissao(first,last,ssn,sales,rate)
{
    cout<<"Construtor baseplus de "<<getFname()<<" chamado\n";
    setBsal(salary);
}
BasePlus::~BasePlus(){
    cout<<"Destrutor baseplus de "<<getFname()<<" chamado\n";
}
void BasePlus::setBsal(double salary){
    bSal = (salary>0?salary:0);
}
double BasePlus::getBsal() const{
    return bSal;
}

double BasePlus::lucro() const{
    return bSal + Comissao::lucro();
}
void BasePlus::printd() const{
 
    Comissao::print();
}