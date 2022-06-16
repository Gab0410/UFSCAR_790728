#include <iostream>
using namespace std;

#include "base1.h"
#include "base2.h"
#include "derivada.h"

int main(){

    Base1 b1(10), *base1Ptr=0;
    Base2 b2('Z'), *base2Ptr=0;
    Derivada d(7,'A',3.5);

    cout<<" Objeto base1 contem inteiro "<< b1.getData()
    <<"\nObjeto base2 contem caracter "<<b2.getData()
    <<"\nObjeto derivado contem:\n "<<d<<"\n\n";

    cout<<" Inteiro "<< d.Base1::getData()
    <<"\nCaracter "<<d.Base2::getData()
    <<"\nNumero real:\n "<<d.getReal()<<"\n\n";

    base1Ptr = &d;
    cout<<"base1Ptr->getData() retorna: "<<base1Ptr->getData()<<"\n";

    base2Ptr = &d;
    cout<<"base2Ptr->getData() retorna: "<<base2Ptr->getData()<<"\n";

    return 0;



}