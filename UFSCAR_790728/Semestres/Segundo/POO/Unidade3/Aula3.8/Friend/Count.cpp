#include <iostream>
#include "Count.h"
using namespace std;

Count::Count()
    :x(0)
    {}
void Count::print(){
    cout<<x<<endl;
}
void setX(Count &c, int val){
    c.x = val;
}
