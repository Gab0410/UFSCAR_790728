#ifndef E2_H
#define E2_H

#include <iostream>
using namespace std;

class MEU_INT
{
    friend ostream &operator<<(ostream &, MEU_INT);
    friend MEU_INT operator+(int , MEU_INT );
    private:
        int x;
    public:
        //construtor padrão com argumento default
        MEU_INT(int v=1) { x = v;}
        // operador + com MEU_INT
        MEU_INT operator+(MEU_INT);
        // operador + com um inteiro
        MEU_INT operator+(int);
};


#endif