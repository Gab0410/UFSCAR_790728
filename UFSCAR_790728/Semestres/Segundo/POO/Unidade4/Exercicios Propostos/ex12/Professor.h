#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pess.h"

namespace poo {

    class Professor:public Pess{
        public:
            Professor(string,int,double);
            virtual double getSal() const;
            virtual void imprime() const;
        private:
            double salario;
    };
}

#endif /* PROFESSOR_H */