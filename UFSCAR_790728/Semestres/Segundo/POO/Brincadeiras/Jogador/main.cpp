#include <iostream>
#include<string>
using namespace std;
#include "Jogador.h"

void painel(){
    cout<<"A seguir entre com os atributos do seu jogador, a seguir segue a ordem de cada atributo\n";
    cout<<"FORÇA = 0\nFINALIZACAO = 1\nSPRINT = 2\nSTAMINA = 3\nCABECEIO = 4\nDESARME = 5\nPASSE = 6\n"<<
    "CRUZAMENTO = 7\nREFLEXO = 8\nSAIDA GOLEIRO = 9\n"<<endl;
}
void painel2(){
    cout<<"Essa sao as posicoes disponiveis {GOL,ZAG,LD,LE,MC,PE,PD,ATA}, Digite uma a seguir: ";

}

int main(){

    painel();
    int vet[10];
    cout<<"\nDigite abaixo os valores: \n";
    for(int i=0;i<10;i++){
        cin>>vet[i];
    }
    string pos;
    painel2();
    cin>>pos;
    Habilidade dados1(vet,pos);

    Jogador goleiro("Navas", 30,1,"K. Navas",dados1);

    goleiro.dadosJog();

    Habilidade dados2(vet,pos);

    Jogador meia("Felipinho",31,1,"Felipones",dados2);

    meia.dadosJog();
    



}