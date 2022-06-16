#include <iostream>
#include <string.h>

using namespace std;

class GradeBook{
    private:
        string courseName;
    public:
        void displayMessage(); //pode ser diferente o nome do parametro da chamada para o do prototipo
        void setCourseName(string name);
        string getCourseName();      
};
/*Esse método imprime uma mensagem de boas vindas personalizada, e nela, há a chamada de outro método que é o que retorna o valor de "courseName*/
void GradeBook::displayMessage(){
    cout<<"Bem-vindo(a) à seu GradeBook do curso de "<<getCourseName()<<"."<<endl;
}
/*Esse método tem como funcionalidade setar o atributo privado "courseName" para o valor que está na variavel "nome", logo como é um método pertencente a 
mesma classe, tem o pode de alterar o atributo, mesmo esse sendo privado*/
void GradeBook::setCourseName(string name){
    courseName = name;
}
/*Esse método tem como funcionalidade apenas retornar o atributo courseName, que se encontra privado, mas como esse método pertence a mesma classe ele tem 
aceeso */
string GradeBook::getCourseName(){
    return courseName;
}

int main(){
    string course; //variavel local
    GradeBook myGradeBook; //grafia camelo, criação do objeto
    cout<<"Nome inicial do curso"<<myGradeBook.getCourseName()
    <<endl; //tenta pegar pelo metodo "get" o nome do curso
    cout<<"Digite o nome do curso:"<<endl; 
    getline(cin,course); //entrada do nome do curso
    cout<<endl;
    myGradeBook.setCourseName(course); //seta o nome do curso para a variavel "course"
    myGradeBook.displayMessage(); //escreve a mensagem personalizada
    return 0;
}