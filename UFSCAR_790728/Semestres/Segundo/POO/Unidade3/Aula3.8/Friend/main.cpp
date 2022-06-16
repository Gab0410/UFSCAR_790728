#include <iostream>
using namespace std;

#include "Count.h"

int main(){
    Count counter;

    cout<<"counter.x apos a inicialização = "<<endl;
    counter.print();

    setX(counter, 8);
    cout<<"counter.x apos a modificacao = "<<endl;
    counter.print();
}