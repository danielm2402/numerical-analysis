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

struct resultado_mul{
  bool encontrada;
  double raiz;
  int iteraciones;
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
    
    resultado_mul raiz(double x0, 
                       double x1, 
                       double x2,
                       int max_iter, 
                       double tolerancia){
      
      resultado_mul sol_mul;
      sol_mul.encontrada = false;
     
      //cout << ">> Tabla Muller " << endl;
      
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
      //Paso 1
      double h1 = x1 - x0;
      double h2 = x2 - x1;
      
      double d1 = (f(x1) - f(x0)) / h1;
      double d2 = (f(x2) - f(x1)) / h2;
      
      double a = (d2 - d1) / (h2 + h1);
      
      int iter = 2;
      
      //Paso 2
      while (iter < max_iter && sol_mul.encontrada == false){
        //Paso 3
        double b = d2 + (h2 * a);
        double c = f(x2);
        //Hallar la solucion a la ecuacion cuadratica
        
        double D = sqrt((b * b) - (4 * a * c));
        //Paso 4
        double E = b - D;
        if (fabs(b - D) < fabs(b + D)) {
          E = b + D;
        }
        //Paso 5
        double h = (-2.0 * c) / E;			
        //. apro
        double x3 = x2 + h;			
        //paso 6
        double er = (x3 -x2) / x3;
        
        cout
          << setw(10)
          << x3
          << setw(10)
          << f(x0)
          << setw(15)
          <<er
          <<endl;
        
        //Verificacion
        if(fabs(er) < tolerancia){
          sol_mul.encontrada = true;
          sol_mul.raiz = x3;
          sol_mul.iteraciones=iter;
          return sol_mul;
        }else{
          //siguiente aproximacion
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
      return sol_mul;
    }
      
private:
        function<double(double)> func;
        string str_func;
        
        double f(double x) {
          return func(x);
        }
};

#endif

