#include <iostream>

using namespace std;

int main(){
    float media,soma;
    float nota[3];
    int j;
    const int PI = 3;
    int v;

    cout<<"Entre com as 3 notas do aluno:\n"<<endl;
    for(j=0;j<3;j++){
        cin>>nota[j];
        soma += nota[j];
    }
    media = soma / 3;
    cout<<"A media das notas =  "<<media<<endl;
    v = PI * 4;
     cout<<"A variavel v =  "<<v<<", a variavel PI = "<<PI<<endl;

}