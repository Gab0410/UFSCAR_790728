#include <iostream>
#include "HourlyEmployee.h"


using namespace std;

hourEmployee::hourEmployee(const string &first,const string &last,const string &ssn, double hwage,double hworked)
    :Comissao(first,last,ssn)
    {
        setWage(hwage);
        setHoras(hworked);
    }
void hourEmployee::setWage(double hourlyW){
    wage = (hourlyW > 0?hourlyW:0);
}
double hourEmployee::getWage() const{
    return wage;
}
double hourEmployee::getHoras() const{
    return horas;
}
void hourEmployee::setHoras(double e){
    horas = (((e>= 0) && (e<=168.0))?e:0);
}
double hourEmployee::earnings() const{
    if(getHoras() <= 40)
        return getWage() * getHoras();
    return 40* getWage() + ((getHoras() - 40)*getWage()*1.5);
}
void hourEmployee::print() const{
    cout<<"Hourly employee: ";
    Comissao::print();
    cout<<"\nhourly wage: "<<getWage()
    <<"; hours worked: "<<getHoras()<<"\n";
}