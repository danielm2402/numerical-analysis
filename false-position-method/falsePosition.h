//
// Created by Daniel Muñoz on 2/21/21.
//

#ifndef FALSE_POSITION_METHOD_FALSEPOSITION_H
#define FALSE_POSITION_METHOD_FALSEPOSITION_H
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using std::endl;
using std::cout;
using std::setw;
using std::string;
using std::function;

class falsePosition{
public:
    falsePosition( function<double(double)> p_func, string s_func) :func(p_func), str_func(s_func){}

    bool findRoot( double a,double b,double tolerance,int max_inter,double &raiz){
        cout<<"Finding root to"<<endl;
        cout<<str()<<endl;
        double A, B, Fa, Fb, x, lastX,Fx;
        int i=0;
        A=a;
        B=b;
        Fa = f(A);
        Fb = f(B);
        if(Fa*Fb<0.0){
            while(i<max_inter){
                x=((A*Fb) - (B*Fa))/(Fb-Fa);
                Fx= func(x);
                double er=fabs((x - lastX)/x);
                if(er*100<tolerance){
                    cout<<er<<endl;
                    raiz= x;
                    return true;
                }
                if(Fa*Fx>0.0){
                    A= x;
                }else{
                    B=x;
                }
                Fa = f(A);
                Fb = f(B);
                cout<<x<<endl;
                lastX=x;
                i++;
            }
        }

        return false;
    }
    double f(double x){
        return func(x);
    }
    string str(){
        return str_func;
    }
private:
    function<double(double)> func;
    string str_func;
};
#endif //FALSE_POSITION_METHOD_FALSEPOSITION_H
