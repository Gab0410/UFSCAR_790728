#include "Pessoa.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace poo{


    Pessoa::Pessoa(string n,int i){
        setNome(n);
        setIdade(i);
    }
    Pessoa::~Pessoa(){
    }

    void Pessoa::setIdade(int x){
        idade = (x>0 && x < 120?x:0);
    }

    int Pessoa::getIdade() const{
        return idade;
    }

    void Pessoa::setNome(string n){
        nome = (n.length() > 0?n:"Sem Nome");
    }

    string Pessoa::getNome() const{
        return nome;
    }

    bool Pessoa::adicionaAnimal(Animal* animal){
       if(listaAnimais.size() < 20){
           listaAnimais.push_back(animal);
           return true;
       }
       return false;
    }

    bool Pessoa::removeAnimal(string n){
        if(!listaAnimais.empty()){
            int i=0;
            while(i<listaAnimais.size() && listaAnimais[i]->getNome() != n)
                i++;
            listaAnimais.erase(listaAnimais.begin()+i);
            return true;
          
          }
        return false;
        }
    
    Animal* Pessoa::obtemAnimal(string n){
        if(!listaAnimais.empty()){
            int i=0;
            while(i<listaAnimais.size() && listaAnimais[i]->getNome() != n)
                i++;
            return listaAnimais[i];
          }

         return 0;
    }

    int Pessoa::qtdeAnimais(){
        return listaAnimais.size();
    }

    int Pessoa::qtdCachorros(){
        int contador=0,i=0;
        while(i<listaAnimais.size()){
            if(listaAnimais[i]->getEspecie() == "Cachorro")
                contador++;
        }
        return contador;
    }

     int Pessoa::qtdePeixes(){
        int contador=0,i=0;
        while(i<listaAnimais.size()){
            if(listaAnimais[i]->getEspecie() == "Peixe")
                contador++;
        }
        return contador;
    }

    bool Pessoa::comparaNome(const Animal* f1, const Animal* f2){
        return f1->getNome() < f2->getNome();
    }

    void Pessoa::imprime(int criterio){

        sort(listaAnimais.begin(), listaAnimais.end(), comparaNome);

        for(int i=0;i<listaAnimais.size();i++){
            if( (listaAnimais[i]->getEspecie() == "Cachorro") && ((criterio==2) || (criterio==0)) ){
                cout<<"Animal ["<<i+1<<"]:\n";
               listaAnimais[i]->imprime();
            }
            else if( (listaAnimais[i]->getEspecie() == "Peixe") && ((criterio==1) || (criterio==0)) ){
                cout<<"Animal ["<<i+1<<"]:\n";
                listaAnimais[i]->imprime();
            }
        }
        cout<<"\n\n";
    }


}
