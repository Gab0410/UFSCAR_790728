#include <iostream>
using namespace std;
#include <iomanip>

#include "SalesPerson.h"

//Inicia o construtor
SalesPerson::SalesPerson(){
    for(int i=0;i<12;i++)
        sales[i] = 0.0;
}
void SalesPerson::getSalesUser(){
    double salesFigure;
    for(int i=1;i<=12;i++){
        cout<<"Entre com a quantidade de vendar no mes "<<i<<":"<<endl;
        cin>>salesFigure;
        setSales(i,salesFigure);
    }
}
void SalesPerson::setSales(int m,double a){
    if(m>= 1 && m <=12 && a >0)
        sales[m-1] = a;
    else
        cout<<"Dados invalidos"<<endl;
}
void SalesPerson::printSales(){
    cout<<setprecision(2)<<fixed<<"O total de vendas no ano foi: R$"
    <<totalSales()<<endl;
}
double SalesPerson::totalSales(){
    double total=0.0;
    for(int i=0;i<12;i++)
        total += sales[i];
    return total;
}