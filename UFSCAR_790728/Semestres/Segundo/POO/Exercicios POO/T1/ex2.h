#include <iostream>
#include<string>
#include<cstring>
#include <stdbool.h>

#include "ex1.h"

using namespace std;
class Aluno:public Pessoa{
    private:
        int ra;
        double n1,n2,t1,t2,t3;
    public:
        Aluno(string, int, int, double, double, double,double,double);
        ~Aluno();
        int getRA();
        void imprime(Aluno);
        double media();
        bool aprovado(double m);
        bool sac(double n);
        double notaSAC(double j);
};
Aluno::Aluno(string nome,int cpf,int RA, double nota1,double nota2,double trab1,double trab2,double trab3){
        
    ra = RA;
    n1 = nota1;
    n2 = nota2;
    t1 = trab1;
    t2 = trab2;
    t3 = trab3;
}
Aluno::~Aluno(){}

int Aluno::getRA(){
    return ra;
}
void Aluno::imprime(Aluno a){
        cout<<"Nome: "<<a.getNome()<<endl;
        cout<<"CPF: "<<a.getCPF()<<endl;
        cout<<"MF: "<<a.media()<<endl;
}
double Aluno::media(){
    double mp,mt,mf;

    mt=(t1+2*t2+3*t3)/6;
    mp = (n1+n2)/2;
    mf = (mp*8+mt*2)/10;

    return mf;
}
bool Aluno::aprovado(double m){
    if(m>=6)
        return true;
    return false;   
}
bool Aluno::sac(double n){
    if(n>=5.0 && n<6.0)
        return true;
    return false;
}
double Aluno::notaSAC(double j){
    double ns;

    ns=12-j;
    return ns;
}