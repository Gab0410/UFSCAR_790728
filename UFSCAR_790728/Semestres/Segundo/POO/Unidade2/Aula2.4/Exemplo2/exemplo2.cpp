#include <iostream>
#include <string.h>

using namespace std;

class GradeBook{
    public:
        void displayMessage(string nameOfCourse); //pode ser diferente o nome do parametro da chamada para o do prototipo
            
        
};
void GradeBook::displayMessage(string courseName){
    cout<<"Bem-vindo(a) à seu GradeBook do curso de "<<courseName<<"."<<endl;
}

int main(){
    string course;
    GradeBook myGradeBook; //grafia camelo
    cout<<"Digite o nome do curso:"<<endl;
    getline(cin,course);
    cout<<endl;
    myGradeBook.displayMessage(course);
    return 0;
}