using namespace std;
#include <cstring>
#include<string>
#include <iostream>

#include "alunos.h"

Alunos::Alunos(int i,string n,int ra)
    :Pessoas(i,n)
{
    setRA(ra);
}
void Alunos::setRA(int ra){
    RA = ra;
}
int Alunos::getRa() const{
    return RA;
}
void Alunos::imprime() const{
    cout<<"Nome: "<<getNome()
    <<"\nIdade: "<<getIdade()
    <<"\nRA: "<<getRa()<<endl;
}