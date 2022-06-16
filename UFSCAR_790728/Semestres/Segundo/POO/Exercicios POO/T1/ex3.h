#include <iostream>
#include<string>
#include<cstring>
#include <stdbool.h>
using namespace std;

class DataHorario{
    private:
        int dia, mes,ano,hora,minuto,segundo;
    public:
        DataHorario(int,int,int,int,int,int);
        ~DataHorario();
        int compara(DataHorario&);
        int getDia();
        int getMes();
        int getAno();
        int getMinuto();
        int getHora();
        int getSegundo();

        void imprime(bool);
        void imprimePorExtenso();
};
DataHorario::DataHorario(int d, int m, int a, int h, int min, int s){
    dia = (d>0 && d<31?d:1);
    mes = (m>0 && m<=12?m:1);
    ano = (a>-1?a:1);
    hora = (h>=0 && h<24?h:1);
    minuto = (m>=0 && m<60?m:1);
    segundo = (s>=0 && s<60?s:1);
}
DataHorario::~DataHorario(){}

int DataHorario::getAno(){
    return ano;
}
int DataHorario::getMes(){
    return mes;
}
int DataHorario::getDia(){
    return dia;
}
int DataHorario::getHora(){
    return hora;
}
int DataHorario::getMinuto(){
    return minuto;
}
int DataHorario::getSegundo(){
    return segundo;
}

int DataHorario::compara(DataHorario &a){
    if((this->ano > a.ano) &&(this->mes>a.mes)&&(this->dia >a.dia) && (this->hora >a.hora) && (this->minuto > a.minuto) && (this->segundo > a.segundo))
        return -1;
    else  if((this->ano < a.ano) &&(this->mes < a.mes)&&(this->dia  < a.dia) && (this->hora  < a.hora) && (this->minuto < a.minuto) && (this->segundo < a.segundo))
        return 1;
    return 0;
}

void DataHorario::imprime(bool t){
    if(t == false){
        cout<<dia<<"/"<<mes<<"/"<<ano<<" "<<hora<<":"<<minuto<<":"<<segundo<<endl;
    }
    else{
        cout<<dia<<"/"<<mes<<"/"<<ano<<" "<<((hora>12?hora-12:hora))<<":"<<minuto<<":"<<segundo<<" "<<((hora>=12?"PM":"AM"))<<endl;

    }
}
void DataHorario::imprimePorExtenso(){

    string meses[12]= {"Janeiro","Fevereiro","Marco","Abril", "Maio", "Junho","Julho","Setembro","Outubro","Novembro","Dezembro"};
    
    cout<<dia<<"de"<<meses[mes-1]<<"de"<<ano<<"-"<<hora<<" horas, "<<minuto<<"minutos, "<<segundo<<endl;

}