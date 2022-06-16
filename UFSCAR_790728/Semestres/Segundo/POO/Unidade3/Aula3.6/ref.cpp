#include<iostream>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

class vetor{
    private:
        int *elementos;
        int total;
    public:
        vetor();
        vetor(vetor &);
};
vetor::vetor( ) {
    int i;
    for (i=0;i<10;i++)
    elementos[i] = -1;
total = 0;
}
/*vetor::vetor(vetor &x){
    int i;
    for(i=0;i<10;i++)
        elementos[i] = x.elementos[i];
    total = x.total;
    */
/*Com a a alocação estatatica, há a copia dos valores do construtor para o construtor copia, ou seja todos os atributos, são copiados para o outro vetor, mas
uma alteração no atributo copia, não resulta em uma alteração no atributo original
*/
/*Entretando, caso o atributo seja um ponteiro, ao fazer esse contrutor copia, ambos os atributos irão apontar para o mesmo endereço, e dessa forma, o atributo
copia, caso alterado/destruido irá alterar/destruir o atributo original, resultando em uma falha de segurança, uma quebra no encpasulmaento do programa*/

//SOLUÇAÕ
vetor::vetor(vetor &x){
    int i;
    elementos = new int [10]; //alocação do novo vetor

    for(i=0;i<10;i++)
        elementos[i] = x.elementos[i];
    total = x.total;
/*Dessa forma, o novo vetor, tera todos os valores do vetor original, mas não tera a fragilidade que o outro metodo tinha */
}