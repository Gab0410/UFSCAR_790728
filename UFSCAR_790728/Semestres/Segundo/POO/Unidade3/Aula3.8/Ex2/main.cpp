#include<iostream>
using namespace std;
#include "Employ.h"

int main(){
    Date birth(7,24,1949);
    Date hire(3,12,1988);
    Employ manager("Bob","Blue", birth, hire);

    cout<<endl;
    manager.print();

    cout<<"Testar construtores com valores invalidos: "<<endl;
    Date folga(14,35,1994);
    cout<<endl;

    Date meczada(2,29,2020);
    return 0;
}