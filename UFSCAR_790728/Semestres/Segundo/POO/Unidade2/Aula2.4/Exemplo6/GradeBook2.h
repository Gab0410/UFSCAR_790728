#include <string.h>

using namespace std;

class GradeBook{
    private:
        string courseName;
    public:
        GradeBook(string nomeCurso);
        GradeBook();
        void displayMessage(); //pode ser diferente o nome do parametro da chamada para o do prototipo
        void setCourseName(string name);
        string getCourseName();      
};