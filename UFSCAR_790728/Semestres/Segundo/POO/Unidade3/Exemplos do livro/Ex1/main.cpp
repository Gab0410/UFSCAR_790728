#include <iostream>
#include "Time.h"

using namespace std;

int main(){
    TIME arrayTime[3];

    for(int i=0;i<3;i++){
        cout<<"Horario inicial(universal) do vetor "<<i<<endl;
        arrayTime[i].printUniversal();
        cout<<"Horario inicial(standard) do vetor "<<i<<endl;
        arrayTime[i].printStandard();
        cout<<"\n";
    }

    cout<<"Os vetores tiverem os horarios arrumados"<<endl;
    arrayTime[0].setTime(20,61,2);
    arrayTime[1].setTime(24,9,45);
    arrayTime[2].setTime(9,36,75);

    for(int j=0;j<3;j++){
        cout<<"Horario modificado(universal) do vetor "<<j<<endl;
        arrayTime[j].printUniversal();
        cout<<"Horario modificado(standard) do vetor "<<j<<endl;
        arrayTime[j].printStandard();
        cout<<"\n";
    }


}