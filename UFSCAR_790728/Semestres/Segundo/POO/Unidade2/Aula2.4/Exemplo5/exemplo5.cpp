#include<iostream>
#include"GradeBook.h"
using namespace std;
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