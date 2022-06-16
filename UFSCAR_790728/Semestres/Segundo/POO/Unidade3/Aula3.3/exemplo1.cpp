#include <iostream>
#include <stdlib.h>

class VETOR{
    public:
        VETOR(int=10); //construtor padrao
        ~VETOR(); //destrutor
        int getTam() const; //tamanho
    private:
        int tam;
        int *ptr;
};
VETOR::VETOR(int T){
    //faz a validação do vetor
    tam = (T>0?T:10);
    ptr = new int[tam]; //aloca o vetor
    for(int i=0;i<tam;i++)
        ptr[i] = 0;//Inicializa o vetor com 0
}
VETOR::~VETOR(){
    delete [] ptr;
}