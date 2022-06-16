
#include <stdlib.h>
#include <iostream>
#include <stdbool.h>

using namespace std;
class lampada {
    private:

        //Atributos    
        int voltagem;
        bool estado;

    public:
        lampada(); //construtor sem parametro
        lampada(int v); // construtor com parametro
        void ligar_desligar(); //simula o interruptor de ligar/desligar

        bool get_estado(); //obtem o estado da lampada
        int get_voltagem();//obtem a voltagem da lampada
        void imprime(); //imprime os atributos da lampada(voltagem e estado)

}; //definição da classe deve terminar com ";" igual às structs em C
/*Os atributos geralmente ficam na area "private" da classe e os métodos na area "public", isso acontece pois desejamos proteger o acesso aos atributos 
de forma a evitar que o objeto tenha valores indevidos, como por exemplo, a voltagem pode ser somente 110V ou 220V, e se desejasse assumir 145V, em C isso era 
possível visto que structs apenas agrupavam valores, e não os protegia, agora com a classe, o projetista, pode entregar ao usuário apenas os métodos publicos
->Deve haver um construtor com o mesmo nome da classe para inicializar o objeto

Se no programa principal o programador criar o objeto L sem parametro, então o construtor sem parametros é chamado, caso contrario, se o programador
definir o objeto L(220) entao a lampada L tera 220V*/
lampada ::lampada() {
    voltagem = 110;
    estado = false;
}
lampada::lampada(int v) {
    if(v == 110 || v == 220)
        voltagem = v;
    else
        voltagem = 110;
    estado = false;
}
/*Ambos os construtores são apresentados no código anterior. Note que a voltagem seá 110 sempre que o valor for diferente de 220, isso impedira a criação
de um objeto com voltagem diferente de 110V ou 220V, e a lampada sempre estara desligada*/
void lampada::ligar_desligar(){
    estado = !estado;
}
/*Para acender ou apagar uma lampada, é necessario acionar o interruptor, o método inverterá o estado da lâmpada
Os métodos get são responsavei pela obtenção dos valores armazenados nos atributos de acesso restrito(private)*/

bool lampada::get_estado(){
    return estado;
}
int lampada::get_voltagem(){
    return voltagem;
}
void lampada::imprime(){
    cout << "estado = "<<estado <<endl;
    cout << "voltagem = "<<voltagem <<endl;
}

int main(){
    lampada sala(9), cozinha(220), escritorio;
    escritorio.imprime();

    cout << "estado das lampadas \n";
    cout << "sala " << sala.get_estado() <<endl;
    cout <<"cozinha " <<cozinha.get_estado() <<endl;
    cout <<"escritorio " <<escritorio.get_estado() <<endl;
    sala.ligar_desligar();

    return(EXIT_SUCCESS);
}