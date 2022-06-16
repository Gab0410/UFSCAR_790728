#include <iostream>
#include "ex2.h"

using namespace std;


MEU_INT MEU_INT::operator+(MEU_INT v){
    
    MEU_INT Z;

    Z.x = x + v.x;

    return Z;
}
MEU_INT MEU_INT::operator+(int a){
    MEU_INT Z;

    Z.x = x + a;
    return Z;
}
MEU_INT operator+(int a,MEU_INT b){
    MEU_INT Z;

    Z.x = a + b.x;

    return Z;
}
ostream &operator<<(ostream &out, MEU_INT w){
    out<<w.x;
    return out;
}
