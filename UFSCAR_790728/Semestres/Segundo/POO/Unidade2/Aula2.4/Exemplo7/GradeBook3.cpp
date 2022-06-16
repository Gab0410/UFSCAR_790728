#include <iostream>
#include "GradeBook3.h"

using namespace std;

//Construtor com parametros
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
    //Condição que verifica se o curso tem até 25 caracteres
    if(name.length() <= 25)
        courseName = name;
    else{
        //Caso falso, é reduzido para 25 caracteres
        courseName = name.substr(0,25);
        cout<<"Nome->"<<name<<"<-excede o limite de 25 caracteres, e será reduzida para 25 caracteres"<<endl;
        cout<<"Resultando em \""<<courseName<<"\""<<endl;
        cout<<"\n"<<endl;
    }
}
/*Esse método tem como funcionalidade apenas retornar o atributo courseName, que se encontra privado, mas como esse método pertence a mesma classe ele tem 
aceeso */
string GradeBook::getCourseName(){
    return courseName;
}
