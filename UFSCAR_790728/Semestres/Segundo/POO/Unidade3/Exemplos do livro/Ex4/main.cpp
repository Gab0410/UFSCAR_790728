#include <iostream>
using namespace std;

#include "Tempo.h"

int main(){
    Tempo desc[5];
    Tempo teste(2);

    desc[0].setTempo(0,0,0);
    desc[1].setTempo(2,0,0);
    desc[2].setTempo(21,34,0);
    desc[3].setTempo(12,25,42);
    desc[4].setTempo(27,74,99);

    for(int i=0;i<5;i++){
        cout<<"Vetor "<<i<<" construção do tipo standart:";
        desc[i].printStandard();
        cout<<"\nVetor"<<i<<" construção do tipo universal: ";
        desc[i].printUniversal();
        cout<<"\n";
    }
    cout<<"Hora definida para 2, e o resto com valores default, standart: ";
    teste.printStandard();
    cout<<"\nHora definida para 2, e o resto com valores default, universal: ";
    teste.printUniversal();
    return 0;
}