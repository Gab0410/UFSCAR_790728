#include <iostream>
using namespace std;

class Count{
    public:
        void setX(int value){
        x = value;
        }
    
        void print(){
            cout<<x<<endl;  
        }
    private:
        int x;
};

int main(){
    Count counter;
    Count *counterPtr = &counter;
    Count &counterRef = counter;

    cout<<"Setar x para 1, usando o nome do objeto:"<<endl;
    counter.setX(1);
    counter.print();

    cout<<"Setar x para 2, usando a referencia a um objeto:"<<endl;
    counterRef.setX(2);
    counterRef.print();

    cout<<"Setar x para 3, usando um ponteiro para um objeto: "<<endl;
    counterPtr->setX(3);
    counterPtr->print();

    return 0;
}
/*Nesse exemplo, é mostrado que um objeto pode ser criado de varias formas, e as funções membros
desse objeto podem ser chamadas de diferentes formas, tanto por ponteiros, referencias à objetos
e a variaveis normais.*/