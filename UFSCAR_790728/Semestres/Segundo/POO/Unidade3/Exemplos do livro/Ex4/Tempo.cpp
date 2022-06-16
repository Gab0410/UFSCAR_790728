#include <iostream>
using namespace std;
#include <iomanip>

#include "Tempo.h"

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
int Tempo::getHora(){
    return hora;
}
int Tempo::getMin(){
    return minuto;
}
int Tempo::getSeg(){
    return segundo;
}
void Tempo::printUniversal(){
    cout<<setfill('0')<<setw(2)<<hora<<":"
    <<setw(2)<<minuto<<":"<<setw(2)<<segundo<<endl;
}
void Tempo::printStandard(){
    cout<<((hora==0 || hora == 12)? 12: hora % 12)<<":"
    <<setfill('0')<<setw(2)<<minuto<<":"<<setw(2)
    <<segundo<<((hora < 12) ?" AM" : " PM");
}
