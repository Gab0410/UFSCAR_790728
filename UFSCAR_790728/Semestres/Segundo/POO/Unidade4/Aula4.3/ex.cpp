#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "ex.h"

using namespace std;

bool bixesto(int year){
    if(year%4==0){
        return true;
    }
    return false;
}
Data::Data(int d,int m,int a){
    setAno(a);
    setMes(m);
    setDia(d);
}
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 2000;
}

void Data::setDia(int d){
    if(d>0 && d<29){
        dia = d;
    }
    else if(d == 29 && mes == 2 && bixesto(ano))
        dia = d;
    else if(d==30 && (mes == 4 || mes== 6 || mes==9 || mes==11)){
        dia = d;
    }
    else if(d==31 && (mes == 1 || mes==3 || mes==5 || mes==7 || mes== 8 || mes==10 || mes==12))
        dia = d;
    else  
        dia = 1;  
}
void Data::setMes(int m){
    mes = (m>0 && m<13?m:1);
}
void Data::setAno(int a){
    ano = (a>0 && a<2021?a:2000);
}
int Data::getDia() const{
    return dia;
}
int Data::getMes() const{
    return mes;
}
int Data::getAno() const{
    return ano;
}
void Data::imprime() const{
    cout<<getDia()<<"/"<<getMes()<<"/"<<getAno()<<endl;
}

//Classe Pessoa
pessoa::pessoa() {
    strcpy(nome,"Ana");
    strcpy(sobrenome,"Silva");
    nascimento.setAno(2010);
    nascimento.setDia(1);
    nascimento.setMes(1);
}
pessoa::pessoa(char *n, char *s) {
    strcpy(nome,n);
    strcpy(sobrenome,s);
    nascimento.setAno(2010);
    nascimento.setDia(1);
    nascimento.setMes(1);
}
void pessoa::setNome(char *x){
    strcpy(nome,x);
}

void pessoa::setSobrenome(char *x) {
    strcpy(sobrenome,x);
}
char * pessoa::getNome() {
    return nome;
}
char * pessoa::getSobrenome() {
    return sobrenome;
}
void pessoa::imprime() {
    cout << getNome() << ", " << getSobrenome() << endl;
    nascimento.imprime();
}
void pessoa::setData(int d, int m, int a) {
    nascimento.setDia(d);
    nascimento.setMes(m);
    nascimento.setAno(a);

/* Esse é um exemplo de composição */