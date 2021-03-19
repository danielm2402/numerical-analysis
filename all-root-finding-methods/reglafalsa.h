#ifndef REGLAFALSA_H
#define REGLAFALSA_H
#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

struct resultado_regfa{
  bool encontrada;
  double raiz;
  int iteraciones;
};

class reglafalsa {
public:
  reglafalsa(
            function<double(double)> p_func,
            string p_str
            ):func(p_func),str_func(p_str) {
  }
  string str(){
    return str_func;
  }
  resultado_regfa raiz(double xi, 
            double xs, 
            int max_iter, 
            double tolerancia) {
    
    resultado_regfa sol_reg;
    sol_reg.encontrada = false;
    int iter = 1;
    
    cout
      <<setw(10)
      <<"p"
      <<setw(10)
      <<"f(p)"
      <<endl;
    
    cout
      << setw(10)
      << xi
      << setw(10)
      << f(xi)
      << setw(15)
      <<"Er"
      <<endl;
    
    if(fabs(f(xi)) < tolerancia){
      sol_reg.encontrada = true;
      sol_reg.raiz = xi;
      return sol_reg;
    }else if (fabs(f(xs)) < tolerancia){
      sol_reg.encontrada = true;
      sol_reg.raiz = xs;
      return sol_reg;
    }
    
    // Teorema del valor intermedio
    if((f(xi) * f(xs)) > 0.0){
      return sol_reg;
    }
    
    double xr = xs  - ((f(xs) * (xi - xs)) / (f(xi) - f(xs)));
   
    if((f(xi) * f(xr)) < 0.0){
      xs = xr;
    }else {
      xi = xr;
    }
    
    while (iter <= max_iter && sol_reg.encontrada == false) {
      
      double xr_ant = xr;
      
      xr = xs - ((f(xs) * (xi - xs)) / (f(xi) - f(xs)));
      
      double er = fabs((xr - xr_ant)/ xr);
      
      cout
        << setw(10)
        << xr
        << setw(10)
        << f(xi)
        << setw(15)
        <<er
        <<endl;
      
      if (fabs(er) < tolerancia){
        sol_reg.encontrada = true;
        sol_reg.raiz = xr;
        sol_reg.iteraciones = iter;
        return sol_reg;
      }
      
      if ((f(xi) * f(xr)) < 0.0){
        xs = xr;
      }else {
        xi = xr;
      }
      iter++;
    }
    return sol_reg;
  }
            
private:
              function<double(double)> func;
              string str_func;
              
              double f(double x) {
                return func(x);
              }
};

#endif
