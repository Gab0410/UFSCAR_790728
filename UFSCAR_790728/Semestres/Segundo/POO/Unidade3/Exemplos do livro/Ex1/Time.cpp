#include <iostream>
#include "Time.h"

using namespace std;

#include <iomanip>

TIME::TIME(){
    hora = minuto = segundo =0;
}
void TIME::setTime(int h,int m, int s){
    hora = (h>=0 && h<24)?h:0;
    minuto = (m>=0 && m<60)?m:0;
    segundo = (s>=0 && s<60)?s:0;
}
void TIME::printUniversal(){
    cout<<setfill('0')<<setw(2)<<hora<<":"
    <<setw(2)<<minuto<<":"<<setw(2)<<segundo<<endl;
}
void TIME::printStandard(){
    cout<<((hora==0 || hora == 12)? 12: hora % 12)<<":"
    <<setfill('0')<<setw(2)<<minuto<<":"<<setw(2)
    <<segundo<<((hora < 12) ?" AM" : " PM");
}
/*Explicando a função printStandart()
=>Primeiro, se hora for igual a 0 ou for igual a 12, é printado 12, caso o contrario é printado o resto da divisao de hora por 12, e.g se hora=20, 20%12=8
=>O setfill, é feito, de modo que caso segundo for 2, fique 02, para fixar uma documentação, isso acontecer junto ao setw(2), que mostra que cada valor, deve
ocupar 2 espaços, no caso completar com 0, se nao houver nada
=>E no final, caso a hora for mais que 12, será AM, que quer dizer que é no periodo da manha/madrugada, já caso hora for maior que 12, é printado PM, que signfica que
é pela parte da tarde/noite.*/