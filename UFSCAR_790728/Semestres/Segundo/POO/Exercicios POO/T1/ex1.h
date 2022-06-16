#include <iostream>
#include<string>
#include<cstring>

using namespace std;

class Pessoa{

    private:    
        string nome;
        int cpf;
    public:
        Pessoa(string, int);
        virtual ~Pessoa();
        string getNome();
        int getCPF();
        void imprime();
};
Pessoa::Pessoa(string n, int num){
    cpf = num;
    nome = n;
}
Pessoa::~Pessoa(){}

string Pessoa::getNome(){
    return nome;
}
int Pessoa::getCPF(){
    return cpf;
}
void Pessoa::imprime(){
    cout<<"Nome: "<<nome<<endl;
    cout<<"CPF: "<<nome<<endl;
}

