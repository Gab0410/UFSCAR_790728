#include <iostream>
using namespace std;
class Ave{
    public:
        virtual void MostraNome() const{
            cout<<"Sou uma ave\n";
        }
        virtual ~Ave(){};
};
class Cisne:public Ave{
    public:
        void MostraNome() const{
            cout<<"Sou um cisne\n";
        }

};
int main(){
    Ave *p_ave = new Cisne;

    p_ave->MostraNome();

    delete p_ave;
}