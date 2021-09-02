#include <iostream>
#include "simpson.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
        simpson s([](double x)->double{
            return exp(x*x);
        },0.0f, 1.0f);
        cout<<"Integral por metodo de Simpson 1/3: "<<s.un_tercio(8)<<endl; //N DEBE SER PAR
        cout<<"Integral por metodo de Simpson 3/8: "<<s.tres_octavos(9)<<endl; //N DEBE SER IMPAR


    return 0;
}
