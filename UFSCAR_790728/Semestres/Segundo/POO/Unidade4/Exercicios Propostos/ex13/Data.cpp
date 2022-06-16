#include "Data.h"

Data::Data(){
   cout<<"Data construida"<<endl;
}
int Data::comparar(const Data other) const{
    if(this->ano != other.ano){
        return this->ano - other.ano;
    }
    else if(this->mes != other.mes)
        return this->mes - other.mes;
    else
        return this->dia - other.dia;
    return 0;
}
bool Data::operator>(const Data& direita) const{
    return comparar(direita) > 0;
}
bool Data::operator>=(const Data& direita) const{
    return comparar(direita) >= 0;
}
bool Data::operator<(const Data& direita) const{
    return comparar(direita) < 0;
}
bool Data::operator<=(const Data& direita) const{
    return comparar(direita) <= 0;
}
bool Data::operator==(const Data& direita) const{
    return comparar(direita) == 0;
}
bool Data::operator!=(const Data& direita) const{
    return comparar(direita) != 0;
}
ostream& operator<<(ostream& out, const Data& obj){
    out << setfill('0') << setw(2) << obj.dia << "/";
    out << setfill('0') << setw(2) << obj.mes << "/";
    out << setfill('0') << setw(4) << obj.ano;
    return out;
}
istream& operator>>(istream& in, Data& obj){
    char c;
    in>>obj.dia>>c>>obj.mes>>c>>obj.ano;
    return in;
}