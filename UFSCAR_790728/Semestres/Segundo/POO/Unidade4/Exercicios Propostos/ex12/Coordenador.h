#ifndef COORDENADOR_H
#define COORDENADOR_H

#include "Professor.h"

namespace poo {

    class Coordenador:public Professor{
        public:
            Coordenador(string,int,double,string);
            virtual double getSal() const;
            string getCurso() const;
            virtual void imprime() const;
        private:
            string curso;
    
    };

}

#endif /* COORDENADOR_H */
