#ifndef EMP_H
#ifndef EMP_H
#define EMP_H
#include<string>

using namespace std;

class Comissao{
    public:
        Comissao(const string &,const string &,const string &);

        ~Comissao();

        void setFname(const string &);
        string getFname() const;

        void setLname(const string &);
        string getLname() const;

        void setSSN(const string &);
        string getSSN() const;

        virtual double earnings() const = 0; //VIRTUAL PURA
        virtual void print() const;

    private:

        string fName;
        string lName;
        string SSN;

};
#endif