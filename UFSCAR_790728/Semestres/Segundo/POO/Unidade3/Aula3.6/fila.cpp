#include<iostream>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

using namespace std;

class fila{
    private:
        char *elemento;
        int t_max,t_atual;
    public:
        fila();
        fila(int);
        ~fila();
        bool insere(char);
        char retira();
        void imprime();
};

fila::fila(){
    cout<<"Construtor sem parametro"<<endl;
    elemento = new char[10];
    if(elemento != NULL){
        t_max = 10;
        t_atual =0;
    }
    else
        exit(1);
}
fila::fila(int t){
    cout<<"Construtor com parametro"<<endl;
    elemento = new char[t];
    if(elemento != NULL){
        t_max = t;
        t_atual =0;
    }
    else
        exit(1);
}
fila::~fila(){
    cout<<"Destrutor"<<endl;

    delete [] elemento;
    elemento = 0; //boa pratica, atribuir 0 ao ponteiro que nao sera mais usado
}
bool fila::insere(char a){
    if(isalpha(a) && t_atual < t_max){
        elemento[t_atual++] = a;
        return true;
    }
    return false;
}
char fila::retira(){
    char letra = elemento[0];
    if(t_atual>0){
        for(int i=0;i<t_atual;i++)
            elemento[i] = elemento[i+1];
        t_atual--;
        return letra;
    }
    return '0';
}
void fila::imprime(){
    for(int i=0;i<t_atual;i++)
        cout<<elemento[i]<<" "<<endl;
    cout<<endl;
}
void tabela(){
    cout << "i ->inserir um elemento na fila" << endl;
    cout << "r -> retirar um elemento da fila" << endl;
    cout << "p -> imprimir a fila" << endl;
    cout << "s -> sair" << endl;

    cout << "Entre com uma das opções do menu!"<< endl;
}
int main() {
    int i;
    char letra, vez, opcao;
    fila padaria(15);
    { // abre novo escopo
        fila estadio_futebol;
    } // fecha escopo – aciona destrutor da fila
    // exibir menu e ler opção do usuário

    tabela();
    cin >> opcao;
    while (opcao != 's'){
    
        if (opcao == 'i') {

            cout << "Entre com uma letra: ";
            cin >> letra;

        if (padaria.insere(letra))
            cout << "inseriu !" << endl;

        else
            cout << "falha na inserção! " << endl;
        }

        if (opcao == 'p')
            padaria.imprime();

        if (opcao == 'r') {
            vez = padaria.retira();

            if (vez != '0')
                cout << "agora é a vez do "<< vez << endl;

            else
                cout << "não tem ninguém na fila! " << endl;
        }
         tabela();
        cin >> opcao;
    }
}
// exibir menu e ler opção do usuário
