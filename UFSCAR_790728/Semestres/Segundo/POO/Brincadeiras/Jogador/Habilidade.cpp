/*class Habilidade{

    private:
        int forca,finaliz,sprint,stamina,cabec,desarme,passe,cruz,reflexo,saidaGol;
        int *ptr;
    public:
        Habilidade(int=50,int=50,int=50,int=50,int=50,int=50,int=50,int=50,int=50,int=50,string="ATA");
        ~Habilidade();
        int calcOver();


};
*/
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "Habilidade.h"
using namespace std;

Habilidade::Habilidade(int vet[10],string pos){
   srand(time(NULL));
    ptr = new int[10];
    for(int i=0;i<10;i++){
        ptr[i] = vet[i];
    }
    
    string lista[] = {"GOL","ZAG","LD","LE","MC","PE","PD","ATA"};
    int aux=0;
    for(int j=0;j<8;j++){
        if(pos == lista[j])
            aux++;
    }
    if(aux==1)
        posica = pos;
    else{
        posica = lista[rand()%9];
        cout<<"Uma posicao invalida foi digitada, a posicao do jogador criado e: "<<posica<<endl;
    }

}
int Habilidade::calcOver(){
    int over;
    if(posica == "GOL"){
        over = (ptr[8]*1.75 + ptr[9]*1.75+ptr[6]*1)/4.5;
    }
    else if(posica=="ZAG"){
        over = (ptr[4]*1.65 + ptr[3]*3+ptr[0]*3+ptr[5]*3+ptr[8]*1)/11.65;
    }
    else if(posica=="LE" || posica=="LD"){
        over = (ptr[7]*2 + ptr[0]*1.5+ptr[2]*2.5+ptr[3]*3+ptr[5]*1.35)/10.35;
    }
    else if(posica=="MC"){
        over = (ptr[6]*4 +ptr[2]*1.5 +ptr[1]*1.35 + ptr[5]*1.75 +ptr[7]*2 +ptr[3]*3.5)/14.1;
    }
    else if(posica=="PE" || posica=="PD"){
        over = (ptr[2]*5+ptr[1]*3+ptr[6]*1.75+ptr[7]*2+ptr[3]*3)/14.75;
    }
    else if(posica=="ATA"){
        over = (ptr[0]*3+ptr[1]*4+ptr[4]*3+ptr[8]*1+ptr[2]*5)/16;
    }
    else{
        over=50;
        cout<<"Gabao, deu merda"<<endl;
    }
    return over;

}
//Habilidade::~Habilidade(){}
void Habilidade::limpa(){
    delete [] ptr;
}

string Habilidade::getPos(){
    return posica;
}
/*
forca 0
finaliz 1
sprint 2
stamina 3
cabec 4
desarme 5
passe 6
cruz 7
reflexo 8
saidaGol 9

GOleiro: reflxo saida gol passe
zagueiro: cabecei stamina força desarme, reflexo
lateral: cruzamento força sprint stamnina,desarme
meias: passe, sprint finalização desarme, cruzmaneto, stamnia
ponta: sprint finalização passa cruzamento, stamnia
atacante: força finalização cabeceio, reflexo, sprint*/
