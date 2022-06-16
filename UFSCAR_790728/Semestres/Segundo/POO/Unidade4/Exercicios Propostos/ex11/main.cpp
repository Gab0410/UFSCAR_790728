#include "Triangulo.h"
#include "Equilatero.h"
int main() {
    Triangulo t1(3,4,5);
    Equilatero t2(3);

    t1.imprime();

    cout << endl;
    cout<<"Comparacao entre t1 e t2: "<<endl;
    if(t1.compare(t2) == -1)
        cout<<"A area de t2>t1"<<endl;
    else if(t1.compare(t2) == 1)
        cout<<"A area de t1>t2"<<endl;
    else
        cout<<"A area de t1 == t2"<<endl;
    cout<<"\n\n";
    t2.imprime();

    return 0;
}