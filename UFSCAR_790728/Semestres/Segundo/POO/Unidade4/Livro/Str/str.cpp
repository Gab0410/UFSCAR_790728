#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "str.h"

using namespace std;

String::String(const char *s)
    : tam((s!=0)?strlen(s):0)
    {
        cout<<"Conversion (and default) constructor: "<<s<<endl;
        setString(s);
    }
String::String(const String &copy)
    :tam(copy.tam)
{
    cout<<"Copy constructor: "<<copy.sPtr<<endl;
    setString(copy.sPtr);
}
String::~String(){
    cout<<"Destructor: "<< sPtr<<endl;
    delete [] sPtr;
}
const String &String::operator=(const String &right){
    cout<<"Operator= called"<<endl;
    if(this != &right){

        delete [] this->sPtr;
        tam = right.tam;
        setString(right.sPtr);
    }
    else
        cout<<"Attempted assignment of a String to itself"<<endl;
    return *this;
}

const String &String::operator+=(const String &right){
    size_t novoTam = tam + right.tam;
    char *tempPtr = new char[novoTam+1];

    strcpy(tempPtr, sPtr);
    strcpy(tempPtr+tam, right.sPtr);

    delete [] sPtr;
    sPtr = tempPtr;
    tam = novoTam;

    return *this;
}
bool String::operator!() const{
    return tam == 0;
}
bool String::operator==(const String &right) const{
    return strcmp(sPtr,right.sPtr) == 0;
}
bool String::operator<(const String &right) const{
    return strcmp(sPtr,right.sPtr) < 0;
}
bool String::operator>(const String &right) const{
    return strcmp(sPtr,right.sPtr) >0;
}
bool String::operator!=(const String &right) const{
    return !(*this == right);
}
char &String::operator[](int sub){
    if(sub < 0 || sub >= tam){
        cout<<"Tamanho invalido"<<endl;
        exit(1);
    }
    return sPtr[sub];
}
char String::operator[](int sub) const{
    if(sub < 0 || sub >= tam){
        cout<<"Tamanho invalido"<<endl;
        exit(1);
    }
    return sPtr[sub];
}
String String::operator()(int index, int substring)const{
    if(index<0 || index>=tam || substring ==0)
        return "";
    int len;
    if( substring == 0 || index+substring>tam){
        len = tam - index;
    }
    else
        len = substring;

    char *tempPtr = new char[len+1];
    strncpy(tempPtr,&sPtr[index],len);
    tempPtr[len] = '\0';
    String tempString(tempPtr);
    delete [] tempPtr;
    return tempString;
}
int String::getTam() const{
    return tam;
}
void String::setString(const char *string2){
    sPtr = new char[tam+1];

    if(string2 != 0)
        strcpy(sPtr,string2);
    else
        sPtr[0] = '\0';
}
ostream &operator<<(ostream &out, const String &s){
    out<<s.sPtr;
    return out;
}
istream &operator>>(istream &in, String &s){
    char temp[100];
    in>>setw(100)>>temp;
    s = temp;
    return in;
}