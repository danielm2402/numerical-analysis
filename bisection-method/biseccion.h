//
// Created by Daniel Muñoz on 2/19/21.
//

#ifndef BISECTION_METHOD_BISECCION_H
#define BISECTION_METHOD_BISECCION_H
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using std::function;
using std::cout;
using std::endl;
using std::setw;
using std::string;

class biseccion {
public:
    biseccion(
            function<double(double)> p_func,
            string s_func
            ) :
            func(p_func), str_func(s_func){

    }

    void imprimirTabla(double a, double b, int intervalos) {
        double paso= (b-a)/intervalos;
        cout<<str()<<endl;
        cout
        <<setw(10)
        <<"x"
        <<setw(10)
        <<"f(x)"
        <<endl;
        while(a<=b+paso){
            cout
            <<setw(10)
            <<a
            <<setw(10)
            <<f(a)
            <<endl;
            a+=paso;
        }
    }
    double f(double x){
        return func(x);
    }
    string str(){
        return str_func;
    }
    bool encontrarRaiz(
            double a,
            double b,
            double tol,
            int max_inter,
            double &raiz
           ){
        int i=1;
        double x_ant = (a+b)/2.0;
        if(fabs(f(x_ant))<tol){
            raiz = x_ant;
            return true;
        }
        if(f(a)*f(x_ant)>0){
         a= x_ant;
        }else{
            b = x_ant;
        }
        while(i<=max_inter){
            double x_nueva = (a+b)/2.0;
            double er=fabs((x_nueva - x_ant)/x_nueva);
            if(fabs(f(x_nueva))<tol || er <tol){
                raiz= x_nueva;
                return true;
            }
            i++;
            if(f(a)*f(x_nueva)>0.0){
                a=x_nueva;
            }else{
                b = x_nueva;
            }
            x_ant=x_nueva;
        }
    }

private:
    function<double(double)> func;
    string str_func;
};

#endif //BISECTION_METHOD_BISECCION_H
