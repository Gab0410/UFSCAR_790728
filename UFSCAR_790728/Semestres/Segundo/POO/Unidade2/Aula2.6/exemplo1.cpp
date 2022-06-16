#include <iostream>
#include<stdbool.h>
#include <stdlib.h>

using namespace std;

class horario{

    private:
        int hora,minuto,segundo;
    public:
        horario(); //construtor
        horario(int, int, int);//construtor com parametros
        void ajusta_hora(int);
        void ajusta_minuto(int);
        void ajusta_segundo(int);
        void imprime();
};
horario::horario(){
    hora =0;
    minuto =0;
    segundo =0;
}
horario::horario(int h,int m,int s){
    hora = (h>=0 && h<24)?h:0;
    minuto = (m>=0 && m<60)?m:0;
    segundo = (s>=0 && s<60)?s:0;
}
void horario::ajusta_hora(int nova_hora){
    hora = (nova_hora>=0 && nova_hora<24)?nova_hora:0;
}
void horario::ajusta_minuto(int nova_m){
    minuto = (nova_m>=0 && nova_m<60)?nova_m:0;
}
void horario::ajusta_segundo(int nova_s){
    segundo = (nova_s>=0 && nova_s<60)?nova_s:0;
}
void horario::imprime(){
    cout<<hora<<":"<<minuto<<":"<<segundo <<endl;
}

int main(){
    horario x;
    x.ajusta_hora(30);
    x.imprime();
}