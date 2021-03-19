#include<cmath>
#include<iomanip>
#include<iostream>
#include <string>
#include "newtonraphson.h"
#include "reglafalsa.h"
#include "secante.h"
#include "muller.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;

void findRoots( function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations  );
void findRoots2( function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations  );
void findRoots3( function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations  );

void falsePosition(function<double(double)> func, string labelfunc ,double tolerance, int iterations, double xi, double xs );
void newtonRaphson(function<double(double)> func, function<double(double)> dfunc ,string labelfunc ,double tolerance, int iterations, double p0);
void secantMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations, double x0, double x1 );
void mullersMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations,double xm0, double xm1, double xm2 );

int main (int argc, char *argv[]) {
    //EJERCICIO 1
    findRoots([](double x) -> double{ return pow(x,6)+(3.25 * pow(x,5))-(41.6 * pow(x,4))-(87.15 * pow(x,3))+(400.8 * pow(x,2)) + 444.5*x - 720;},
              "x^6 + 3.25x^5 - 41.6x^4 - 87.15x^3 + 400.8x^2 + 444.5x - 720",
              [](double x) -> double {return 6*pow(x,5)+(16.25*pow(x,4))-(166.4*pow(x,3))-(261.45*pow(x,2))+801.6*x+444.5;}
            ,0.00000001,
              100 );
    // EJERCICIO 2
    findRoots2([](double x) -> double{ return 25000*(x*pow(1+x,6)/pow(1+x,6)-1)-5500;},
              "25000( (x(1+x)^6) / (1+x)^6-1)-5500",
              [](double x) -> double {return((25000*(-6*x*pow(x+1,5)+pow(x+1,12)-pow(x+1,6)))/(pow(pow(x+1,6)-1,2)));}
              ,0.0000000001,
              100 );

    //EJERCICIO 3
    findRoots3([](double x)->double {return pow(x,7)- 28.002*pow(x,6)+322*pow(x,5)+1960*pow(x,4)-6769*pow(x,3)-13132*pow(x,2)+13068*x-2500;},
              "x^7-28.002x^6+332x^5+1960x^4-6769x^3-13132x^2+13068x-2500",
              [](double x)->double{return 7*pow(x,6)-168.012*pow(x,5)+1660*pow(x,4)+7840*pow(x,3)-20307*pow(x,2)-26264*x+13068 ;}
              ,0.00000001,
              100
              );

	return 0;
}

void findRoots(function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations){
    cout<<"#################################"<<endl;
    cout<<"######### FINDING ROOTS "<<"#########"<<endl;
    cout<<"#################################"<<endl;
    cout<<""<<endl;
    cout
            <<setw(5)
            <<"f(x)= "
            <<label
            <<endl;
    cout<<""<<endl;
    cout
            <<setw(10)
            <<"Tolerance"
            <<setw(20)
            <<"Max iterations"
            <<endl;
    cout
            <<setw(10)
            <<tolerance
            <<setw(10)
            <<iterations
            <<endl;
    cout<<""<<endl;
    falsePosition(func, label, tolerance, iterations, 4.5, 5.5);
    newtonRaphson(func, dfunc, label,tolerance, iterations, 4.5);
    mullersMethod(func, label, tolerance, iterations, 4.5, 5.0,5.5);
    cout<<""<<endl;
}
void findRoots2(function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations){
    cout<<"#################################"<<endl;
    cout<<"######### FINDING ROOTS "<<"#########"<<endl;
    cout<<"#################################"<<endl;
    cout<<""<<endl;
    cout
            <<setw(5)
            <<"f(x)= "
            <<label
            <<endl;
    cout<<""<<endl;
    cout
            <<setw(10)
            <<"Tolerance"
            <<setw(20)
            <<"Max iterations"
            <<endl;
    cout
            <<setw(10)
            <<tolerance
            <<setw(10)
            <<iterations
            <<endl;
    cout<<""<<endl;
    falsePosition(func, label, tolerance, iterations, 1.0, 1.4);
    secantMethod(func, label, tolerance, iterations, 1.0 ,1.4);
    mullersMethod(func, label, tolerance, iterations, 1.0, 1.2,1.4);
    cout<<""<<endl;
}
void findRoots3(function<double(double)> func, string label, function<double(double)> dfunc, double tolerance, int iterations){
    cout<<"#################################"<<endl;
    cout<<"######### FINDING ROOTS "<<"#########"<<endl;
    cout<<"#################################"<<endl;
    cout<<""<<endl;
    cout
            <<setw(5)
            <<"f(x)= "
            <<label
            <<endl;
    cout<<""<<endl;
    cout
            <<setw(10)
            <<"Tolerance"
            <<setw(20)
            <<"Max iterations"
            <<endl;
    cout
            <<setw(10)
            <<tolerance
            <<setw(10)
            <<iterations
            <<endl;
    cout<<""<<endl;
    falsePosition(func, label, tolerance, iterations, 3.0, 4.0);
    secantMethod(func, label, tolerance, iterations, 3.0 ,4.0);
    mullersMethod(func, label, tolerance, iterations, 3.0, 3.5,4.0);
    cout<<""<<endl;
}

void falsePosition(function<double(double)> func, string labelfunc ,double tolerance, int iterations, double xi, double xs ){
    cout<<""<<endl;
    cout<<"1. FALSE POSITION"<<endl;
    reglafalsa regf(func,labelfunc);
    resultado_regfa sol_reg = regf.raiz(xi,xs, iterations, tolerance);
    cout<<""<<endl;
    if(sol_reg.encontrada){
        cout
                <<setw(15)
                <<"|Root"
                <<setw(15)
                <<"Iterations|"
                <<endl;
        cout
                <<setw(11)
                <<"|"<<sol_reg.raiz
                <<setw(14)
                <<sol_reg.iteraciones<<"|"
                <<endl;
    }else{
        cout << "Not found "<<endl;;
    }
}
void newtonRaphson(function<double(double)> func, function<double(double)> dfunc ,string labelfunc ,double tolerance, int iterations, double p0 ){
    cout<<""<<endl;
    cout<<"2. NEWTON RAPHSON"<<endl;
    newtonraphson newtr(func, dfunc, labelfunc);
    resultado_newRap sol_ne = newtr.encontrarRaiz(p0, iterations, tolerance);
    cout<<""<<endl;
    if(sol_ne.encontrada){
        cout
                <<setw(15)
                <<"|Root"
                <<setw(15)
                <<"Iterations|"
                <<endl;
        cout
                <<setw(11)
                <<"|"<<sol_ne.raiz
                <<setw(14)
                <<sol_ne.iteraciones<<"|"
                <<endl;
    }else{
        cout << "Not found"<<endl;;
    }
}
void secantMethod(function<double(double)> func, string labelfunc ,double tolerance, int iterations, double x0, double x1 ){
    cout<<""<<endl;
    cout<<"3. SECANT METHOD"<<endl;
    secante sec(func, labelfunc);
    resultado_seca sol_sec = sec.raiz(x0, x1, iterations, tolerance);
    cout<<""<<endl;
    if(sol_sec.encontrada){
        cout
                <<setw(15)
                <<"|Root"
                <<setw(15)
                <<"Iterations|"
                <<endl;
        cout
                <<setw(11)
                <<"|"<<sol_sec.raiz
                <<setw(14)
                <<sol_sec.iteraciones<<"|"
                <<endl;
    }else{
        cout << "Not found"<<endl;
    }
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