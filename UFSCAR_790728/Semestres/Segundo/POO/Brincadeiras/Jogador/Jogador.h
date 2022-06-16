#ifndef JOG_H
#define JOG_H
using namespace std;

#include <string>
#include<cstring>

#include "Habilidade.h"

class Jogador{
    friend Habilidade;
    private:
        static int camisa[20]/*{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}*/;
        int numCamisa;
        string nome;
        int idade;
        string nCamisa;
        string posicao;
        int overall;
    public:
        Jogador(string name, int age,int shirtNu, string shirtNa, Habilidade over);
        ~Jogador();
        int verifica(int);
        int getCamisa() const;
        string getNome() const;
        int getIdade() const;
        int getOver() const;
        string getnCamis() const;
        void dadosJog() const;
};


#endif
/*
Jogador tem camiseta, nome, idade, nome da camisa, posição. overall
habilidades
-> força, finalização, sprint, stamina, cabeceio, desarme, passe, cruzamento,reflexo, saida gol

GOleiro: reflxo saida gol passe
zagueiro: cabecei stamina força desarme, reflexo
lateral: cruzamento força sprint stamnina
meias: passe, sprint finalização desarme, cruzmaneto, stamnia
ponta: sprint finalização passa cruzamento, stamnia
atacante: força finalização cabeceio, reflexo, sprint
*/