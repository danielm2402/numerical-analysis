#include <iostream>
#include<cmath>
#include<iomanip>
#include <string>
#include "muller.h"

void mullersMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations,double xm0, double xm1, double xm2 );


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void mullersMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations,double xm0, double xm1, double xm2 ){
    cout<<""<<endl;
    cout<<"4. MULLER'S METHOD"<<endl;
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