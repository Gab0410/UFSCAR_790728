#include "Universidade.h"

Universidade::Universidade(string n)
    :nome(n)
    {
        cout<<"Construtor da universidade "<<nome;
        max = 2;
        qntd = 0;

        deptos = new Departamento*[max];
    }
Universidade::~Universidade(){
    cout<<"Destrutor da universidade "<<nome<<endl;
    delete [] deptos;
}
string Universidade::getNome() const{
    return nome;
}
void Universidade::setNome(string s){
    nome = s;
}
void Universidade::adicionaDepto(string n,string s){
    if(qntd==max)
        realoca(max+5);
    deptos[qntd++] = new Departamento(n,s,this);//aciona o construtor

}
void Universidade::removeDepto(string s){
    bool sit = false;

    int i=0;

    while(i<qntd && !sit){
        if(deptos[i]->getSigla() == s)
            sit = true;
        else
            i++;
    }
    if(sit){
        delete deptos[i];
        while(i<qntd){
            deptos[i] = deptos[i+1];
            i++;
        }
        qntd -= 1;
        if(qntd == max-5){
            realoca(max-5);
        }
    }

}
void Universidade::imprime() const{
    cout<<"Departamentos da "<<nome<<endl;
    for(int i=0;i<qntd;i++){
        deptos[i]->imprime();
    }
}
void Universidade::realoca(int tam){
    max = tam;

    Departamento**aux= new Departamento*[max];

    for(int i=0;i<qntd;i++){
        aux[i] = deptos[i];
    }
    delete deptos;
    deptos = aux;
}