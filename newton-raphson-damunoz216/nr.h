//
// Created by Daniel Muñoz on 2/22/21.
//
#include <functional>
#include <string>
#include <iomanip>
#include <iostream>
using std::function;
using std::string;
using std::cout;
using std::endl;
using std::setw;
#ifndef NEWTON_RAPHSON_DAMUNOZ216_NR_H
#define NEWTON_RAPHSON_DAMUNOZ216_NR_H
class clsNewtonRaphson{
public:
    clsNewtonRaphson(
            function<double(double)> p_func,
    function<double(double)> p_dfunc,
    string p_sfunc
            ):func(p_func), dfunc(p_dfunc), sfunc(p_sfunc){}

double f(double x){
        return func(x);
    }
    double df(double x){
        return dfunc(x);
    }
    string str(){
        return sfunc;
    }
    void table(double x0, double paso, int n ){
        cout
        <<setw(10)
        <<"x"
        <<setw(10)
        <<"f(x)"
        <<endl;
        double x= x0;
        while(n>0){
            cout
                    <<setw(10)
                    <<x
                    <<setw(10)
                    <<f(x)
                    <<endl;
            x+=paso;
            n--;
        }
    }
    bool foundRoot(double p0, double tol, int iter, double &raiz){
        int i = 1;
        if(fabs(f(p0))<tol){
            raiz = p0;
            return true;
        }
        while (i<iter){
            double p = p0-(f(p0)/df(p0));
            double er=fabs((p0 - p)/p0);
            if(er<tol){
                raiz=p;
                return true;
            }
            i++;
            p0=p;
        }
        return false;
    }
private:
    function<double(double)> func;
    function<double(double)> dfunc;
    string sfunc;
};
#endif //NEWTON_RAPHSON_DAMUNOZ216_NR_H
