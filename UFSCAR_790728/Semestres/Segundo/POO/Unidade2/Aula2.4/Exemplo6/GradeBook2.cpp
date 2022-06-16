#include <iostream>
#include "GradeBook2.h"

using namespace std;

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
