#include <iostream>

using namespace std;

#include "Date.h"

Date::Date(int mn, int da, int yr){
    if(mn > 0 && mn<=12)
        month = mn;
    else
        month = 1;
    if(yr>0 && yr < 2021)
        year = yr;
    else
        year = 2002;
    day = checkDay(da);

    cout<<"Construtor Date para a data: ";
    print();
    cout<<endl;
}
void Date::print() const{
    cout<<day<<"/"<<month<<"/"<<year;
}
Date::~Date(){
    cout<<"Destrutor Date para a data: ";
    print();
    cout<<endl;
}
int Date::checkDay(int dia) const{
    static const int diasAno[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(dia>0 &&( dia <= diasAno[month]))
        return dia;
    if(month == 2 && dia ==29 && year%4==0)
        return dia;
    cout<<"Dia invalido"<<endl;
    return 1;
}