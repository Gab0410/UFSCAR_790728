#include <iostream>
#include <stdbool.h>
#include <string.h>

using namespace std;

class RadioDePilha{
    private:

        //Declaracao dos atributos
        string modulacao;
        bool estado;
        int volume;
        float frequencia;
        int bateria;

        //Metodos privados
        void diminuiBateria();
        void alarmeBateria();
    public:
        RadioDePilha(); 
        void controlaVolume(char s);
        void mudaFrequencia(float canal);
        void liga_desliga();
        void mudaModulacao();
        int getVolume();
        bool getEstado();
        float getFrequencia();
        string getModulacao();
        int getBateria();
};

/*Função: Construtor da classe, inicia os valores default do radio de pilha, ao criar-se o objeto no código principal*/
RadioDePilha::RadioDePilha(){
    modulacao = "AM";
    estado = false;
    volume = 5;
    frequencia = 101.1;
    bateria = 100;
}

/*Função: Se a bateria estiver com 20 de bateria o radio é desligado. */
void RadioDePilha::alarmeBateria(){
    if(bateria <= 20){
        cout<<"---------------------//---------------------"<<endl;
        cout<<"Bateria Muito Baixa, radio sera desligado.\n\n"<<endl;
        cout<<"---------------------//---------------------"<<endl;

        estado = false;
    }
}

/*Função: A cada operação que o usuário faz, a bateria é decrementada em 10 */
void RadioDePilha::diminuiBateria(){
    bateria -= 10;
    alarmeBateria();
}

/*Função: Imprime uma mensagem de erro de operação caso o radio esteja desligado, não faz parte da classe, é uma função a parte */
void imprimeMsg(){
    cout<<"---------------------//---------------------"<<endl;
    cout<<"Radio, desligado, operacao invalida, ligue-o"<<endl;
    cout<<"---------------------//---------------------"<<endl;

}

/*Função: Controla o volume do radio, caso receba + aumenta, caso receba - dimiminui, o radio tem limites de valores entre 0 e 10, e caso 
queira aumentar além disso, o usuario é impedio, essa operação so funciona com o radio ligado,e não recebe valores que nao sejam + ou -, pois na 
entrada há um controle */
void RadioDePilha::controlaVolume(char s){
     if(estado == true){   
        if(s == '+' && volume < 10)
            volume = volume +1;
        else if(s=='-' && volume > 0)
            volume -= 1;
        else{
        cout<<"---------------------//---------------------"<<endl;
        cout<<"Volume ja esta no maximo/minimo possivel, operacao invalida"<<endl;
        cout<<"---------------------//---------------------"<<endl;
        diminuiBateria();
        }
    }
    else
        imprimeMsg();
     
}

/*Função: Liga ou desliga o radio, dependendo de seu estado previo */
void RadioDePilha::liga_desliga(){
    if(estado == true)
        estado = false;
    else
        estado = true;
}

/*Função: Muda a modulação do radio dependendo da sua modulação previa */
void RadioDePilha::mudaModulacao(){
    if(estado == true){
        if(modulacao == "AM")
            modulacao = "FM";
        else
            modulacao = "AM";
    diminuiBateria();
    }
    else
        imprimeMsg();
}

/*Função: Muda a frequencia do radio, os valores alternam entre 0 e 120, caso esteja fora dos limites a operação é invalida, e é apresentada uma mensagem
ao usuario */
void RadioDePilha::mudaFrequencia(float canal){
    if(estado == true){
        if(canal > 0 && canal < 120)
            frequencia = canal;
        else{
        cout<<"---------------------//---------------------"<<endl;
        cout<<"Frequencia fora dos limites, operacao invalida"<<endl;
        cout<<"---------------------//---------------------"<<endl;
          
        }
        diminuiBateria();
        
    }
    else
       imprimeMsg();
        
}

/*Abaixo estao as funções get da classe, que conseguem acessar e retornar os valores do atributos, para interagir e mostrar com/para o usuario */
int RadioDePilha::getVolume(){
    return volume;
}
bool RadioDePilha::getEstado(){
    return estado;
}
float RadioDePilha::getFrequencia(){
    return frequencia;
}
string RadioDePilha::getModulacao(){
    return modulacao;
}
int RadioDePilha::getBateria(){
    return bateria;
}

/*Função: Isto é uma função e não um metodo, e serve para verificar se o valor x está entre o limite inferior(limI) e o limite superior(limS), serve
para controlar as opções do usuario  */
int verifica(int x, int limI, int limS){
    int i=0;
    for(int j=limI;j<limS+1;j++){
        if(x == j)
            i++;
    }
    if(i==1)
        return 1;
    return 0;
}

/*Programa principal */
int main(){
    //Declaração local
    int opcao;

    //Criação do objeto
    RadioDePilha radio;

    //Inicio do do-while
    do{
        //Entrada da opcao
        cout<<"Digite qual opcao abaixo, voce quer que o radio faça\n\n"<<endl;
        cout<<"[1] Ligar/Desligar\n[2] Aumentar/Diminuir Volume\n[3] Mudar Frequencia\n[4] Trocar Modulacao\n[5] Mostrar valores\n[6] Sair\n\nDigite o valor:"<<endl;
        cin>>opcao;

        //Liga/Desliga o radio
        if(opcao == 1)
            radio.liga_desliga();

        //Controla o volume
        else if(opcao == 2){
            
            //Declaração local
            char sinal[1];

            //Entrada do sinal
            cout<<"Para diminuir digite -, para aumentar digite +:"<<endl;
            cin>>sinal[0];

            //Controle de entrada, caso for diferente de + ou -, a entrada é reefeita
            while(sinal[0] != '-' && sinal[0] != '+'){
                cout<<"\n\n\n\n\n\nValor inválido, digite, novamente - ou +"<<endl;
                cin>>sinal[0];
                cout<<"\n\n\n\n\n\n"<<endl;
            }

            //Chamada do método
            radio.controlaVolume(sinal[0]);
        }

        //Controla a frequencia do radio
        else if(opcao == 3){
            
            //Declaração local
            float f;

            //Entrada da frequencia
            cout<<"Digite a frequencia desejada entre 0 e 120:"<<endl;
            cin>>f;

            //Chama o método
            radio.mudaFrequencia(f);
        }

        //Muda a modulacao do radio
        else if(opcao == 4)

            //Chama o método
            radio.mudaModulacao();

        //Mostra os valores do radio
        else if(opcao == 5){

            //Saída de valores dos atributos do objeto
            cout<<"Os valores do sistema abaixo:\n\n----------------//----------------"<<endl;
            cout<<"Estado: "<<radio.getEstado()<<"\nVolume: "<<radio.getVolume()<<"\nFrequencia: "<<radio.getFrequencia()<<"\nModulacao: "
            <<radio.getModulacao()<<"\nBateria: "<<radio.getBateria()<<endl;
            cout<<"----------------//----------------"<<endl;
        
        //Se a bateia for menor ou igual à 20, além da mensagem exibida, a variavel opçao recebe o valor 6, e isso encerra o laço
        if(radio.getBateria() <= 20)
            opcao = 6;   
        }

    //Controle de laço com uma função 
    }while(verifica(opcao,1,5));

    //Finalização
    return 0;
}