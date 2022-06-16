#include <iostream>
using namespace std;
#include <iomanip>

#include "ComissionEmployee.h"
#include "BasePlusC.h"

int main(){
    Comissao comissionE("Sue","Jones","222-22-2222",1000,.06);

    Comissao *comissionEPtr =0;

    BasePlus bPlusCE("Bob","Lewis","333-33-3333",5000,.04,300);
    BasePlus *bPlusCEPTR = 0;

    cout<<fixed<<setprecision(2);

    cout<<"Print classe base e a derivada:\n";
    bPlusCE.print();

    comissionEPtr = &comissionE;

    comissionEPtr->print();

    bPlusCEPTR = &bPlusCE;

    bPlusCEPTR->print();

    comissionEPtr = &bPlusCE;
    cout<<"Chamando print com um ponteiro de classe base apontando para uma classe derivada, chama classe base print: \n";
    comissionEPtr->print();

    return 0;
}