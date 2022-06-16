#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

//Cabeçalho 1A) Pilha.h
class Pilha{
    private:
        int *pilha;
        int tmax, tatual;
        static int contador;
    public:
        Pilha(int tamanho);
        ~Pilha();
        void insere(int);
        int retira();
        int getCont();

};

//Implementação da classe

//Implementação do construtor 1B)

//Instanciação do construtor static, para fazer a soma dos inteiros das pilhas
int Pilha::contador = 0;

//Construtor
Pilha::Pilha(int tamanho){

    //Ponteiro alocado dinamicamente, com tamanho definido pelo usuario
    pilha = new int[tamanho];

    //Verificação se há memoria suficiente
    if(pilha != NULL){
        
        //Instancia os atributos relacionados à tamanho
        tmax = tamanho;
        tatual =0;
    }

    //Caso contrario programa encerra
    else
        exit(1);
}

//Construtor que contem a desalocação dinamica, usando o delete
Pilha::~Pilha(){
    delete [] pilha;
}

//Função Membro insere, que insere valores
void Pilha::insere(int n){

    //A condição ocorre se a pilha não estiver cheio
    if(tmax>tatual){

        //Na posical tatual da pilha, insere o valor de n
        pilha[tatual] = n;

        //soma à variavel static "contador" o valor de n(pilha[tatual])
        contador += pilha[tatual];

        //Como foi adicionado um elemento, tatual é incrementado em 1 posição
        tatual++;
    }
    else
        cout<<"Filha cheia, inserção invalida\n"<<endl;


}

//1C) FUnção membro que retira elementos da pilha
//Função Membro retira(get)
int Pilha::retira(){

    //Se a pilha for não vazia, ou seja tatual maior que zero, terá elemento para serem retirados
    if(tatual >0){

         //Atribui o primeiro elemento da pilha a uma variavel auxiliar
        int saida = pilha[0];

        //Laço para, pegar o elemento i+1, e coloca-lo na posição i, logo todos os valores andam uma posição pra frente, ja que o primeiro valor foi tirado
        for(int i=0;i<tatual;i++)
            pilha[i] = pilha[i+1];
        
        //Um elemento retirado, o tamanho atual é diminuido
        tatual--;

        //Retorna o primeiro elemento, valor definido no inicio do if
        return saida;
    }

    //Caso seja um valor inválido, retorna -999, visto que uma função deve ter um valor de retorno obrigatoriamente
    return -999;
}

//Função getCont, que retorna o contador de valores inteiros da pilha
int Pilha::getCont(){
    return contador;
}


//Possível implementação, para exibir os métodos da classe, e como trabalham entre si.
int main(){
    Pilha p1(3),p2(4);
    for(int i=0;i<3;i++){
        p1.insere(i+1);
    }
     for(int j=0;j<4;j++){
        p2.insere(j+1);
    }

    //Tentativa de inserção com fila cheia
    p1.insere(1000);
    p2.insere(4000);

    //Retirada
    for(int w=0;w<4;w++){
        cout<<"P1[0] = "<<p1.retira()<<endl;
        cout<<"P2[0] = "<<p2.retira()<<endl;
        cout<<"\n";
    }

    //Contadores
    cout<<"\nCONT 1= "<<p1.getCont()<<"\nCont 2= "<<p2.getCont()<<endl;
    return 0;
}