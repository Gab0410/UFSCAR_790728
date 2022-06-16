#include <iostream>
#include <stdlib.h>
using namespace std;

class TESTE{
    public:
        TESTE(int=0);
        void imprime();
    private:
        int x;
};
TESTE::TESTE(int t){
    x = t;
}

void TESTE::imprime(){
    //uso implicito
    cout<<" x = " <<x;
    //uso explicito
    cout<<"\n this->x = " <<this->x;
    //alternativa
    cout<<"\n(*this).x = "<<(*this).x<<endl;
}

int main(){
    TESTE objeto(12);
    objeto.imprime();

    return 0;
}