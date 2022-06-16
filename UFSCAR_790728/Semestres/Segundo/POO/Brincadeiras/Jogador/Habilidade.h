#ifndef HAB_H
#define HAB_H

using namespace std;
#include<string>
#include<cstring>


class Habilidade{

    private:
        //int forca,finaliz,sprint,stamina,cabec,desarme,passe,cruz,reflexo,saidaGol;
        int *ptr;
        string posica;
    public:
        Habilidade(int vet[10],string="ATA");
       // ~Habilidade();
        int calcOver();
        string getPos();
        void limpa();


};



#endif

/*habilidades
-> força, finalização, sprint, stamina, cabeceio, desarme, passe, cruzamento,reflexo, saida gol

GOleiro: reflxo saida gol passe
zagueiro: cabecei stamina força desarme, reflexo
lateral: cruzamento força sprint stamnina
meias: passe, sprint finalização desarme, cruzmaneto, stamnia
ponta: sprint finalização passa cruzamento, stamnia
atacante: força finalização cabeceio, reflexo, sprint*/