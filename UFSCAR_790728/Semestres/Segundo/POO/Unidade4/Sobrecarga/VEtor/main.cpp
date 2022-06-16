#include <iostream>
#include "vetor.h"
using namespace std;

int main(){
    VETOR X1(17);
    VETOR X2;

    cout<<"Tamanho do VETOR X1 e = "<<X1.getTam()
    <<"\nVeotr apos a inicialização:\n"<<X1;

    if(X1!=X2)
        cout<<"X1 e X2 sao diferentes\n";

    VETOR L3(X1);

    X1.setVal(4);
    
    cout<<X1;

    cout<<"\n";

    cin>>L3>>X1;
    cout<<X1<<L3;


    return 0;

}
