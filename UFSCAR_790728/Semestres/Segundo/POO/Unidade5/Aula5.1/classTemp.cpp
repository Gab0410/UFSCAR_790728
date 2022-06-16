#include <iostream>
#include <cstring>

using namespace std;

template <class T>

class Coordenadas{
    private:
        T x,y;
    public:
        Coordenadas(T,T);
        void set(T,T);
        void get(T&,T &) const;
        T getX() const;
        T getY() const;
};

template <class T>
Coordenadas<T>::Coordenadas(T c_x, T c_y){
    this->x = c_x;
    this->y = c_y;
}
template <class T>
void Coordenadas<T>::set(T c_x, T c_y){
    this->x = c_x;
    this->y = c_y;
}
template <class T>
void Coordenadas<T>::get(T &c_x, T &c_y) const{
    c_x = this->x;
    c_y = this->y;
}
template<class T>
T Coordenadas<T>::getX() const{
    return this->x;
}
template <class T>
T Coordenadas<T>::getY() const{
    return this->y;
}
int main(){
    int a,b;
    float c,d;
    double e,f;
    char g,h;
    string i,j;
    bool k,l;
    a = 1;b=2;c=4.5;d=7.8;e=5.6;f=9.75;g='a';h='b';i="correto";j="incorreto";k=true;l=false;
    Coordenadas <int> Pos_inteira(a,b);
    Coordenadas <float> Pos_float(c,d);
    Coordenadas <double> Pos_double(e,f);
    Coordenadas <char> Pos_char(g,h);
    Coordenadas <string> Pos_string(i,j);
    Coordenadas <bool> Pos_bool(k,l);

    cout<<Pos_inteira.getX()<<" "<<Pos_inteira.getY()<<"\n";
    cout<<Pos_float.getX()<<" "<<Pos_float.getY()<<"\n";
    cout<<Pos_double.getX()<<" "<<Pos_double.getY()<<"\n";
    cout<<Pos_char.getX()<<" "<<Pos_char.getY()<<"\n";
    cout<<Pos_string.getX()<<" "<<Pos_string.getY()<<"\n";
    cout<<Pos_bool.getX()<<" "<<Pos_bool.getY()<<"\n";

    Pos_inteira.get(b,a);
    Pos_inteira.set(a,b);
    cout<<Pos_inteira.getX()<<" "<<Pos_inteira.getY()<<"\n";

    return 0;
}