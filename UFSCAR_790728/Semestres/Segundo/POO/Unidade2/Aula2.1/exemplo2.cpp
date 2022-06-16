#include <iostream>

using namespace std;

int x = 2;
int dob(int v){
    return 2*v;
}
int main(){
    int x = 0;
    cout<<"Local = "<<dob(x)<<endl;
    cout<<"Global = "<<dob(::x)<<endl;
    return 0;
}