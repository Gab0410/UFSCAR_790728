#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char letra = 'a';
    cout<<"Pre conversao = "<<letra<<endl;
    int v = letra;
    cout<<"Pos conversao = "<<v<<endl;

    float fReal = 45.60;
    int inteiro,iOutro;
    char caracter = 'W';

    cout<<"Pre conversao , caracter = "<<caracter<<endl;
    cout<<"Pre conversao, fReal = "<<fReal<<endl;

    iOutro = (int)caracter;
    caracter = char(fReal);
    inteiro = (int)fReal;

    cout<<"Pos conversao, fReal = "<<fReal<<endl;
    cout<<"Pos conversao, caracter = "<<caracter<<endl;
    cout<<"Pos conversao, inteiro = "<<inteiro<<endl;
    cout<<"Pos conversao, iOutro = "<<iOutro<<endl; 

    char s[20] = "Objeto S";
    string x; //necessario o uso da biblioteca string.h

    x = "Objeto X";

    cout<<"\n"<<s<<endl;
    cout<<""<<x<<endl;


}