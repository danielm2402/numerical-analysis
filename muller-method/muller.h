#ifndef MULLER_H
#define MULLER_H
#include <cmath>
#include <functional>
#include <iomanip>
#include <string>
#include<iostream>

using std::cout;
using std::endl;
using std::function;
using std::string;

struct result{
  bool found;
  double root;
  int iterations;
};

class muller {
public:
  muller (
          function<double(double)> p_func,
          string p_str
          ): func(p_func), str_func(p_str){
    
  }
  
  string str(){
    return str_func;
  }

    result raiz(double x0,
                       double x1, 
                       double x2,
                       int max_iter, 
                       double tolerancia){

        result result;
        result.find = false;
      
      cout
        <<setw(10)
        <<"p"
        <<setw(10)
        <<"f(p)"
        <<endl;
      
      cout
        << setw(10)
        << x0
        << setw(10)
        << f(x0)
        << setw(15)
        <<"Er"
        <<endl;
      double h1 = x1 - x0;
      double h2 = x2 - x1;
      double d1 = (f(x1) - f(x0)) / h1;
      double d2 = (f(x2) - f(x1)) / h2;
      double a = (d2 - d1) / (h2 + h1);
      int iter = 2;

      while (iter < max_iter && result.found == false){
        double b = d2 + (h2 * a);
        double c = f(x2);
        //Finding quadratic equation
        
        double D = sqrt((b * b) - (4 * a * c));
        double E = b - D;
        if (fabs(b - D) < fabs(b + D)) {
          E = b + D;
        }
        double h = (-2.0 * c) / E;
        double x3 = x2 + h;
        double er = (x3 -x2) / x3;
        
        cout
          << setw(10)
          << x3
          << setw(10)
          << f(x0)
          << setw(15)
          <<er
          <<endl;

        if(fabs(er) < tolerancia){
          result.found = true;
          result.root = x3;
          result.iterations=iter;
          return result;
        }else{
          //new aproximation
          x0 = x1;
          x1 = x2;
          x2 = x3;
          h1 = x1 - x0;
          h2 = x2 - x1;
          
          d1 = (f(x1) - f(x0)) / h1;
          d2 = (f(x2) - f(x1)) / h2;
          
          a = (d2 - d1) / (h2 + h1);
          iter++;
        }
      }
      return result;
    }
      
private:
        function<double(double)> func;
        string str_func;
        
        double f(double x) {
          return func(x);
        }
};

#endif

