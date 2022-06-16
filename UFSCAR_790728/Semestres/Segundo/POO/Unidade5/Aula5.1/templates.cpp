#include <iostream>
#include<cstring>
using namespace std;

template <typename T>
void troca( T & a, T & b){
    T temp(a);
    a = b;
    b = temp;
}

int main(){
    int a,b;
    float c,d;
    double e,f;
    char g,h;
    string i,j;
    bool k,l;

    a = 1;b=2;c=4.5;d=7.8;e=5.6;f=9.75;g='a';h='b';i="correto";j="incorreto";k=true;l=false;
    cout<<"Pre troca:\n";
    cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n"<<f<<"\n"<<g<<"\n"<<h<<"\n"<<i<<"\n"<<j<<"\n"<<k<<"\n"<<l<<"\n";
    troca(a,b);
    troca(c,d);
    troca(e,f);
    troca(g,h);
    troca(i,j);
    troca(k,l);
    cout<<"Pos troca:\n";
    cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n"<<f<<"\n"<<g<<"\n"<<h<<"\n"<<i<<"\n"<<j<<"\n"<<k<<"\n"<<l<<"\n";
}