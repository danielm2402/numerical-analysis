#ifndef SECANTE_H
#define SECANTE_H

#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

struct resultado_seca{
  bool encontrada;
  double raiz;
  int iteraciones;
};

class secante {
public:
  secante(
             function<double(double)> p_func,
             string p_str
             ):func(p_func),str_func(p_str) {
  }
  string str(){
    return str_func;
  }
  resultado_seca raiz(double x0, 
            double x1, 
            int max_iter, 
            double tolerancia) {
    
    resultado_seca sol_sec;
    sol_sec.encontrada = false;
    int iter = 1;
    //imprimir tabla
    
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
    
    double x =0.0;
    double x_ant = 0.0;
    
    do{
      x_ant = x;
      x = x1 - (f(x1) * (x0 -x1)) / (f(x0) - f(x1));
      if (iter > 1){
        
        double er = fabs((x-x_ant)/x);
        
        cout
          << setw(10)
          << x
          << setw(10)
          << f(x0)
          << setw(15)
          <<er
          <<endl;
        
        if(er < tolerancia){
          sol_sec.encontrada = true;
          sol_sec.raiz = x;
          sol_sec.iteraciones = iter;
          return sol_sec;
        }
      }
      x0 = x1;
      x1 = x;
      iter++;
    }while(iter <= max_iter && !sol_sec.encontrada);
    return sol_sec;
  }
            
private:
              function<double(double)> func;
              string str_func;
              
              double f(double x) {
                return func(x);
              }
};


#endif
