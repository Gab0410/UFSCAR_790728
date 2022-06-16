/*Nome dos participantes:

Alexandra Floriano - RA 761771
Alexandre dos Santos Gualberto - RA 790843
Gabriel Meirelles Carvalho Orlando - RA 790728
Marcelina Maye Abaga - RA 790139
Ricardo Araújo da Silva - RA 790919

*/
#include "Racionais.h"
#include <iostream>
using namespace std;

int main(){
    Racionais r1(-4,-6);
    Racionais r2(-6,10);
    Racionais r3(2,3);
    Racionais r4(3,-3);

    cout<<boolalpha<<endl;
    cout<<"r1 => "<<r1<<endl;
    cout<<"r2 => "<<r2<<endl;
    cout<<"r3 => "<<r3<<endl;   
    cout<<"r4 => "<<r4<<endl;

    cout<<"(r1 + r2) => "<<(r1+r2)<<endl;
    cout<<"(r1 - r2) => "<<(r1-r2)<<endl;
    cout<<"(r1 * r2) => "<<(r1*r2)<<endl;
    cout<<"(r1 / r2) => "<<(r1/r2)<<endl;

    cout<<"(r1 < r2) => "<<(r1 < r2)<<endl;
    cout<<"(r1 < r3) => "<<(r1 < r3)<<endl;
    cout<<"(r1 <= r2) => "<<(r1 <= r2)<<endl;
    cout<<"(r1 <= r3) => "<<(r1 <= r3)<<endl;

    cout<<"(r1 == r2) => "<<(r1 == r2)<<endl;
    cout<<"(r1 == r3) => "<<(r1 == r3)<<endl;
    cout<<"(r1 != r2) => "<<(r1 != r2)<<endl;
    cout<<"(r1 != r3) => "<<(r1 != r3)<<endl;

    cout<<"(r1 >= r2) => "<<(r1 >= r2)<<endl;
    cout<<"(r1 >= r3) => "<<(r1 >= r3)<<endl;
    cout<<"(r1 > r2) => "<<(r1 > r2)<<endl;
    cout<<"(r1 > r3) => "<<(r1 > r3)<<endl;
    cout<<endl;

    return 0;
}

