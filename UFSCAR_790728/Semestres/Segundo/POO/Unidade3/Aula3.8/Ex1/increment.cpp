#include <iostream>
#include "increment.h"
using namespace std;

Increment::Increment(int c, int i)
    :counter(c),
    inc(i)
    /*isso é uma lista de inicializadores membro, é necessario, pois caso fosse inc = i, daria erro, pois inc é do tipo const, e essa declaração continua nao
    é permitida pela linguagem */
    {}
void Increment::printI() const{
    cout<<"cout = "<<counter<<", increment = "<<inc<<endl;
}