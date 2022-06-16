#ifndef COMI_H
#define COMI_H
#include<string>

using namespace std;

class Comissao{
    public:
        Comissao(const string &,const string &,const string &, double=0.0,double =0.0);

        void setFname(const string &);
        string getFname() const;

        void setLname(const string &);
        string getLname() const;

        void setSSN(const string &);
        string getSSN() const;

        void setVbruta(double);
        double getVbruta() const;

        void setTaxaCom(double);
        double getTaxaCom() const;

        double lucro() const;
        void print() const;

    private:

        string fName;
        string lName;
        string SSN;
        double vBruta;
        double taxaCom;

};
#endif