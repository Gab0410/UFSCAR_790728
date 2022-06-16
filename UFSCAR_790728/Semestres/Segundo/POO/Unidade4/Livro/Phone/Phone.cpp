#include <iomanip>
using namespace std;

#include "Phone.h"

ostream &operator<<(ostream &out,const Phone &v){
    out<<"O numero de telefone inserio foi: ("<<v.codigoArea<<") "
    <<v.codRegiao<<"-"<<v.linha<<"\n";
    return out;
}
istream &operator>>(istream &in,Phone &v){
    in.ignore();//pula primeiro parenteses
    in>>setw(3) >> v.codigoArea;
    in.ignore(2);//segundo parenteses e espaço
    in>>setw(3)>>v.codRegiao;
    in.ignore(); //ignora o -
    in>>setw(4)>>v.linha;

    return in;


}