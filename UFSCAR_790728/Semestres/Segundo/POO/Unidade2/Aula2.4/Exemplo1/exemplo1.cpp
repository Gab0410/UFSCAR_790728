#include <iostream>

using namespace std;

class GradeBook{
    public:
        void displayMessage();
            
        
};
void GradeBook::displayMessage(){
    cout<<"Bem-vindo(a) à seu GradeBook"<<endl;
}

int main(){
    GradeBook myGradeBook; //grafia camelo
    myGradeBook.displayMessage();
    return 0;
}