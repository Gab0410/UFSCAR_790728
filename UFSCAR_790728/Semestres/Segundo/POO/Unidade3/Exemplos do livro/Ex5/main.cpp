#include <iostream>
using namespace std;

#include "Create&Destroy.h"

void create(void); //prototipo
CreateAndDestroy firts(1,"(antes do main, global)");

int main(){
    cout<<"\n FUNCAO MAIN, INICIO DA EXECUCAO"<<endl;
    CreateAndDestroy second(2,"(escopo local, dentro do main)");
    static CreateAndDestroy third(3,"(static, local no main)");

    create();

    cout<<"FUNCAO MAIN, CONTINUA A EXECUCAO"<<endl;
    CreateAndDestroy fourth(4,"(local, dentro do main)");

    return 0;
}
void create(void){
    cout<<"FUNCAO CREATE, INICIO DA EXECUCAO"<<endl;
    CreateAndDestroy fifth(5,"(local dentro de create)");
    static CreateAndDestroy sixth(6,"(static dentro do create)");
    CreateAndDestroy seventh(7,"(local, dentro do create");
    cout<<"FIM DA EXECUCAO DE CREATE"<<endl;
}