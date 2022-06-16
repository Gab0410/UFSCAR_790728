#include <iostream>
#include <string.h>

using namespace std;

class GradeBook{
    private:
        string courseName;
    public:
        GradeBook(string nomeCurso);
        GradeBook();
        void displayMessage(); //pode ser diferente o nome do parametro da chamada para o do prototipo
        void setCourseName(string name);
        string getCourseName();      
};
GradeBook::GradeBook(string nomeCurso){
    setCourseName(nomeCurso);
}
GradeBook::GradeBook(){
    courseName = "Sem Curso";
}
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
    GradeBook myGradeBook("Bichologia"),myGradeBook2("Introducao ao Pensamento algoritimico"),myGradeBook3; //grafia camelo, criação do objeto
    cout<<"Nome inicial do curso 1: "<<myGradeBook.getCourseName()<<"!"<<endl;
    cout<<"Nome inicial do curso 2: "<<myGradeBook2.getCourseName()<<"!"<<endl;
    cout<<"Nome inicial do curso 2: "<<myGradeBook3.getCourseName()<<"!"<<endl;


    //Alterando valores dos atributos
    cout<<"Digite o nome de seu curso:";
    getline(cin,course);
    cout<<"\n"<<endl;
    myGradeBook.setCourseName(course);
    myGradeBook.displayMessage();
    cout<<"\n"<<endl;
    myGradeBook2.displayMessage();
    cout<<"\n"<<endl;
    myGradeBook3.displayMessage();



  
    return 0;
}