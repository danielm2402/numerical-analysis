#include <iomanip>
#include <iostream>
#include <functional>
#include <cmath>
#include "nr.h"
using std::cout;
using std::endl;
using std::cin;
using std::setw;

void caso(string sfunc, function<double(double)> p_func, function<double(double)> d_func);

int main() {
    caso("f(x)=x^2 - cos(x)",[](double x)->double {
       return pow(x, 2) - cos(x);
   },[](double x)->double {
       return 2*x+sin(x);
   } );
    caso("f(x)=x^3 +4x^2-10",[](double x)->double {
        return pow(x, 3) + 4*pow(x,2)-10;
    },[](double x)->double {
        return 3*x+8*x;
    } );

    caso("f(x)=10-x^2",[](double x)->double {
        return 10-pow(x, 2);
    },[](double x)->double {
        return -2*x;
    } );
    return 0;
}
void caso(string sfunc, function<double(double)> p_func, function<double(double)> d_func){
    cout<<sfunc<<endl;
    clsNewtonRaphson n(p_func,d_func,sfunc);
    n.table(-1.0, 0.1, 20);
    double p0;
    double tol;
    int iter;

    cout << "Enter p0 value: ";
    cin>>p0;
    cout<<"Enter tolerance value: ";
    cin>>tol;
    cout<<"Enter max-value iterations: ";
    cin>>iter;

    double raiz;

    if(n.foundRoot(p0, tol, iter, raiz)){
        cout << "Root Found"<<raiz<<endl;
    }else{
        cout <<"Root Not Found"<<endl;
    }
}
