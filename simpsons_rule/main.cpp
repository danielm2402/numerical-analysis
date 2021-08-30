#include <iostream>
#include "simpson.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
        simpson s([](double x)->double{
            return exp(x*x);
        },0.0f, 1.0f);
        cout<<"Integral por metodo de Simpson 1/3"<<endl;
    return 0;
}
