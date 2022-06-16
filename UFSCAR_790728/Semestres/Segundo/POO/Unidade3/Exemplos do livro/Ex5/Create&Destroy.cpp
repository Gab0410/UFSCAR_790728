#include <iostream>
using namespace std;

#include "Create&Destroy.h"

CreateAndDestroy::CreateAndDestroy(int ID, string m){
    objID = ID;
    msg = m;
    cout<<"Objeto "<<objID<<" exibe a mensagem: "<<msg<<endl;

}
CreateAndDestroy::~CreateAndDestroy(){
    cout<<(objID == 1 || objID == 6 ? "\n":"");
    cout<<"Objeto "<<objID<<" destroi a mensagem "<<msg<<endl;
}