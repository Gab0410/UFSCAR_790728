#include <iostream>
using namespace std;

#include "Stack.h"

int main(){
    Stack<double> doubleStack(5);
    double double_value = 1.1;

    cout<<"Pushing element onte doubleStack\n";

    while (doubleStack.push(double_value))
    {
        cout<<double_value<<" ";
        double_value += 1.1;
    }
    cout<<"Stack is full.Cannot push "<<double_value
    <<"\n\nPoping elements from doublestack\n";

    while (doubleStack.pop(double_value))
        cout<<double_value<<" ";

    
    cout<<"\nStack is empty, cannot push\n";

     Stack<int> intStack;
    int int_value = 1;

    cout<<"Pushing element onte doubleStack\n";

    while (intStack.push(int_value))
    {
        cout<<int_value<<" ";
        int_value += 1;
    }
    cout<<"Stack is full.Cannot push "<<int_value
    <<"\n\nPoping elements from doublestack\n";

    while (intStack.pop(int_value))
        cout<<int_value<<" ";

    
    cout<<"\nStack is empty, cannot push\n";

    return 0;
    
    

}