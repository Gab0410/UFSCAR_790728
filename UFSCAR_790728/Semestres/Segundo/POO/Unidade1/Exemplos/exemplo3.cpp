#include <stdbool.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class jogo{
    private:
        char tab[3][3];
        int jogadas;
        char jogador;
    public:
        jogo();
        bool terminou();
        char verifica_vencedor();
        bool posicionar_peca(int, int);
        void jogar();
        void limpa_tela();
        void troca_jogador();
        void desenhar_tabuleiro();
};
jogo::jogo(){
    int i, j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tab[i][j] = '*';
    jogadas = 0;
    srand(time(NULL));
    if(rand() % 2 ==0 )
        jogador = 'X';
    else
        jogador = 'O';
}

bool jogo::terminou(){
    if(jogadas < 9 && verifica_vencedor() == '*')
        return false;
    return true;
}
char jogo::verifica_vencedor(){
    int c1=0,c2=0,c3=0,c4=0;

    //Verifica linha e coluna
    for(int i=0;i<3;i++){
        c1=0,c2=0,c3=0,c4=0;
        for(int j=0;j<3;j++){
            if(tab[i][j] == 'X')
                c1++;
            else if(tab[i][j] == 'O')
                c2++;
            if(tab[j][i] == 'X')
                c3++;
            else if(tab[j][i] == 'O')
                c4++;
    }
        if(c4 == 3 || c2 == 3)
            return 'O';
        if(c1 == 3 || c3 == 3)
            return 'X';
    }
    //Verifica diagonal
    c1 =0,c2=0,c3=0,c4=0;
    for(int k=0;k<3;k++){
        if(tab[k][k] == 'X')
            c1++;
        else if(tab[k][k] == 'O' )
            c2++;
        if(tab[k][2-k] == 'X')
            c3++;
        else if(tab[k][2-k] == 'O')
            c4++;
    }
    if(c1 == 3 || c3 == 3)
        return 'X';
    if(c2 == 3 || c4 == 3)
        return 'O';
    return '*';
}
bool jogo::posicionar_peca(int a, int b){
    if(tab[a][b] == '*' && a < 3 && b < 3){
        tab[a][b] = jogador;
        jogadas ++;
        return true;
    }
    return false;
}
void jogo::troca_jogador(){
    if(jogador == 'X'){
        jogador = 'O';
    }
    else
        jogador = 'X';
        
}
void jogo::desenhar_tabuleiro(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%c ",tab[i][j]);
        printf("\n");
    }
}

void jogo::jogar(){
    int a,b;
    printf("O jogador que vai jogar e: %c\n",jogador);
    while(!terminou()){
        printf("Digite a posicao [x,y] que voce quer posicionar %c\n",jogador);
        scanf("%d %d",&a,&b);
        while(!posicionar_peca(a,b)){
            printf("\nERRO, casa já está ocupada/nao e valida\n");
            desenhar_tabuleiro();
            printf("\nDigite novamente:\n");
            scanf("%d %d", &a,&b);
        }
        troca_jogador();
        printf("\nO tabuleira esta assim:\n");
        desenhar_tabuleiro();
        printf("\n");
    }
    if(verifica_vencedor() != '*')
        printf("\nO vencedor foi: %c\n",verifica_vencedor());
    else
        printf("\nO jogo terminou empatado!\n");
    printf("\nO jogo terminou em %d jogadas\n", jogadas);
}
int main(){
    jogo partida;
    printf("Vamos jogar jogo da velha:\n\n");
    partida.jogar();
    return 0;
}