#include <iostream>

using namespace std;

int integer1 = 98;

namespace Example
{
    const double PI = 3.14159;
    const double E = 2.71828;

    int integer1 = 8;

    void printValues();

    namespace Inner{
        
        enum Years {FISCAL1=1990,FISCAL2,FISCAL3};
    }
}
namespace{
    double doubleInUnnamed = 88.22;
}

int main(){
    cout<<"doubleInUnnamed = "<<doubleInUnnamed;

    cout<<"\nPI = "<<Example::PI<<"\nE = "<<Example::E
    <<"\nInteger1 = "<<Example::integer1<<"\nFISCAL3 = "
    <<Example::Inner::FISCAL3<<endl;

    Example::printValues();
    return 0;
}
void Example::printValues(){
    cout<<"\nIn printValues: \ninteger1 = "<<integer1<<"\nPI ="
    <<PI<<"\nE = "<<E<<"\ndoubleInUnnamed = "<<doubleInUnnamed<<
    "\n(global) integer 1 = "<<::integer1<<"\nFISCAL3 = "<<Inner::FISCAL3
    <<endl;
}
