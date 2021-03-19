#include <iostream>
#include<cmath>
#include<iomanip>
#include <string>
#include "muller.h"

void mullersMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations,double xm0, double xm1, double xm2 );


int main() {
    mullersMethod([](double x) -> double{ return pow(x,6)+(3.25 * pow(x,5))-(41.6 * pow(x,4))-(87.15 * pow(x,3))+(400.8 * pow(x,2)) + 444.5*x - 720;},
                  "x^6 + 3.25x^5 - 41.6x^4 - 87.15x^3 + 400.8x^2 + 444.5x - 720",
                  0.00000001, 100, 4.5, 5.0,5.5);

    return 0;
}

void mullersMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations,double xm0, double xm1, double xm2 ){
    cout<<""<<endl;
    cout<<"MULLER'S METHOD"<<endl;
    muller mu(func, labelfunc);
    resultado_mul sol_mul = mu.raiz(xm0, xm1, xm2, iterations, tolerance);
    cout<<""<<endl;
    if(sol_mul.encontrada){
        cout
                <<setw(15)
                <<"|Root"
                <<setw(15)
                <<"Iterations|"
                <<endl;
        cout
                <<setw(11)
                <<"|"<<sol_mul.raiz
                <<setw(14)
                <<sol_mul.iteraciones<<"|"
                <<endl;
    }else{
        cout << "Not fount"<<endl;
    }
}