#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>
using namespace std;

class Phone{
    friend ostream &operator<<(ostream &, const Phone &);
    friend istream &operator>>(istream &, Phone &);

    private:
        string codigoArea;
        string codRegiao;
        string linha;
};

#endif