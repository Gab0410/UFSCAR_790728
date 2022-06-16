#include <iostream> /* function declaration */
using namespace std;
void next(void);
static int counter = 7; /* global variable */

int main() {
    while(counter<10){
        next();
        counter++;   
        }
    return 0;
}

void next( void ) {    /* function definition */
   static int iteration = 13; /* local static variable */
   iteration ++;
   cout<<"iteration = "<<iteration<<" and counter = "<< counter<<endl;
}