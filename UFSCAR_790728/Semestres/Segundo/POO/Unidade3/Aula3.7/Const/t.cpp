#include <iostream>
using namespace std;
#include <iomanip>

#include "t.h"

Tempo::Tempo(int h,int m, int s){
    setTempo(h,m,s);
}
void Tempo::setTempo(int hour, int minute, int seconds){
    setHora(hour);
    setMin(minute);
    setSeg(seconds);
}
void Tempo::setHora(int hr){
    hora = (hr>=0 && hr<24)?hr:0;
}
void Tempo::setMin(int min){
    minuto = (min>=0 && min<60)?min:0;
}
void Tempo::setSeg(int seg){
    segundo = (seg >=0 && seg < 60) ? seg:0;
}
int Tempo::getHora() const{
    return hora;
}
int Tempo::getMin() const{
    return minuto;
}
int Tempo::getSeg() const{
    return segundo;
}
void Tempo::printUniversal() const{
    cout<<setfill('0')<<setw(2)<<getHora()<<":"
    <<setw(2)<<getMin()<<":"<<setw(2)<<getSeg()<<endl;
}
void Tempo::printStandard(){
    cout<<((getHora()==0 || getHora() == 12)? 12: getHora() % 12)<<":"
    <<setfill('0')<<setw(2)<<getMin()<<":"<<setw(2)
    <<getSeg()<<((getHora() < 12) ?" AM" : " PM");
}
